#pragma once

#include <vector>
#include <glm\glm.hpp>

using namespace std;

struct BoundingBox
{
	float min_x;
	float min_y;
	float max_x;
	float max_y;

	BoundingBox(float minX, float minY, float maxX, float maxY)
	{
		min_x = minX;
		min_y = minY;
		max_x = maxX;
		max_y = maxY;
	}
};

struct Entity2D
{
	virtual ~Entity2D() = default;
	virtual BoundingBox get_bounding_box() = 0;
protected:
	Entity2D() = default;
};

struct Line2D : Entity2D
{
private:
	glm::vec2 start_point_{};
	glm::vec2 end_point_{};
public:
	Line2D(const glm::vec2& start_point, const glm::vec2& end_point)
	{
		start_point_ = start_point;
		end_point_ = end_point;
	}

	BoundingBox get_bounding_box() override
	{
		auto minX = glm::min(start_point_.x, end_point_.x);
		auto minY = glm::min(start_point_.y, end_point_.y);
		auto maxX = glm::max(start_point_.x, end_point_.x);
		auto maxY = glm::max(start_point_.y, end_point_.y);
		return BoundingBox(minX, minY, maxX, maxY);
	}
};

/**
 * \brief A.K.A LwPolyline
 */
struct PolyLine2D : Entity2D
{
private:
	vector<glm::vec2> vertices_;
public:
	PolyLine2D(const vector<glm::vec2>& vertices)
	{
		vertices_ = vertices;
	}

	BoundingBox get_bounding_box() override
	{
		auto min_x = numeric_limits<float>::max();
		auto min_y = numeric_limits<float>::max();
		auto max_x = numeric_limits<float>::min();
		auto max_y = numeric_limits<float>::min();

		for (const auto vertex : vertices_)
		{
			if (vertex.x < min_x)
				min_x = vertex.x;
			if (vertex.y < min_y)
				min_y = vertex.y;
			if (vertex.x > max_x)
				max_x = vertex.x;
			if (vertex.y > max_y)
				max_y = vertex.y;
		}
		return BoundingBox(min_x, min_y, max_x, max_y);
	}
};

struct Circle2D : Entity2D
{
protected:
	glm::vec2 center_;
	float radius_;
public:
	Circle2D(const glm::vec2& center, const float& radius)
	{
		center_ = center;
		radius_ = radius;
	}

	BoundingBox get_bounding_box() override
	{
		return BoundingBox(center_.x - radius_, center_.y - radius_,
		                   center_.y - radius_, center_.y + radius_);
	}
};

struct Arc2D : Circle2D
{
private:
	/**
	 * \brief radian
	 */
	float start_angle_;
	/**
	 * \brief radian
	 */
	float end_angle_;
	bool is_ccw_;
public:
	Arc2D(const glm::vec2& center, const float& radius,
	      const float start_angle, const float end_angle, const bool is_ccw = true): Circle2D(center, radius)
	{
		start_angle_ = start_angle;
		end_angle_ = end_angle;
		is_ccw_ = is_ccw;
	}

	BoundingBox get_bounding_box() override
	{
		const auto adjustedStartAngle = is_ccw_ ? start_angle_ : end_angle_;
		const auto adjustedEndAngle = is_ccw_ ? end_angle_ : start_angle_;

		// Convert angles to radians if they are in degrees
		const auto start_x = center_.x + radius_ * std::cos(adjustedStartAngle);
		const auto start_y = center_.y + radius_ * std::sin(adjustedStartAngle);
		const auto end_x = center_.x + radius_ * std::cos(adjustedEndAngle);
		const auto end_y = center_.y + radius_ * std::sin(adjustedEndAngle);
		// Determine the minimum and maximum values in both x and y directions
		const auto min_x = std::min(start_x, end_x);
		const auto min_y = std::min(start_y, end_y);
		const auto max_x = std::max(start_x, end_x);
		const auto max_y = std::max(start_y, end_y);
		return BoundingBox(min_x, min_y, max_x, max_y);
	}
};
