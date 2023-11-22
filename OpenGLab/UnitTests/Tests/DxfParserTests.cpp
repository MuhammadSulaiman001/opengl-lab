#include "pch.h"
#include <filesystem>
#include <fstream>
#include <glm/ext/scalar_constants.hpp>
#include <sys/stat.h>
#include "DxfParser.h"

using namespace std;

namespace dxf_parser_tests
{
	TEST(DxfParserTests, test_files_should_exist)
	{
		filesystem::exists("./test-files/art1.dxf");
		filesystem::exists("./test-files/art2.dxf");
		filesystem::exists("./test-files/bismillah.dxf");
		filesystem::exists("./test-files/catty.dxf");
	}

	TEST(DxfParserTests, get_entities_should_return_the_exact_content_of_art1_file)
	{
		DxfParser dxfParser("./test-files/art1.dxf");
		auto entities = dxfParser.get_entities();
		EXPECT_EQ(entities.size(), 1796);
		auto arcs = filter<Entity2D, Arc2D>(entities);
		EXPECT_EQ(arcs.size(), 1668);
		auto lines = filter<Entity2D, Line2D>(entities);
		EXPECT_EQ(lines.size(), 128);

		BoundingBox boundingBox = dxfParser.get_bounding_box(entities);
		EXPECT_GT(boundingBox.min_x, -5.0);
		EXPECT_GT(boundingBox.min_y, 5.0);
		EXPECT_LT(boundingBox.max_x, 775.0);
		EXPECT_LT(boundingBox.max_y, 520.0);
	}

	TEST(DxfParserTests, get_entities_should_return_the_exact_content_of_art2_file)
	{
		DxfParser dxfParser("./test-files/art2.dxf");
		auto entities = dxfParser.get_entities();
		EXPECT_EQ(entities.size(), 617);
		auto circles = filter<Entity2D, Circle2D>(entities);
		EXPECT_EQ(circles.size(), 1);
		auto arcs = filter<Entity2D, Arc2D>(entities);
		EXPECT_EQ(arcs.size(), 616);

		auto boundingBox = dxfParser.get_bounding_box(entities);
		EXPECT_GT(boundingBox.min_x, -60.0);
		EXPECT_GT(boundingBox.min_y, 0.0);
		EXPECT_LT(boundingBox.max_x, 650.0);
		EXPECT_LT(boundingBox.max_y, 600.0);
	}

	TEST(DxfParserTests, get_entities_should_return_the_exact_content_of_catty_file)
	{
		DxfParser dxfParser("./test-files/catty.dxf");
		auto entities = dxfParser.get_entities();
		EXPECT_EQ(entities.size(), 103);
		auto circles = filter<Entity2D, Circle2D>(entities);
		EXPECT_EQ(circles.size(), 1);
		auto arcs = filter<Entity2D, Arc2D>(entities);
		EXPECT_EQ(arcs.size(), 86);
		auto lines = filter<Entity2D, Line2D>(entities);
		EXPECT_EQ(lines.size(), 16);

		auto boundingBox = dxfParser.get_bounding_box(entities);
		EXPECT_GT(boundingBox.min_x, 25.0);
		EXPECT_GT(boundingBox.min_y, 6.0);
		EXPECT_LT(boundingBox.max_x, 33.0);
		EXPECT_LT(boundingBox.max_y, 13.0);
	}

	TEST(DxfParserTests, get_entities_should_return_the_exact_content_of_bismillah_file)
	{
		DxfParser dxfParser("./test-files/bismillah.dxf");
		auto entities = dxfParser.get_entities();
		EXPECT_EQ(entities.size(), 1336);
		auto lines = filter<Entity2D, Line2D>(entities);
		EXPECT_EQ(lines.size(), 1336);

		auto boundingBox = dxfParser.get_bounding_box(entities);
		EXPECT_GT(boundingBox.min_x, -5.0);
		EXPECT_GT(boundingBox.min_y, -5.0);
		EXPECT_LT(boundingBox.max_x, 11.0);
		EXPECT_LT(boundingBox.max_y, 13.0);
	}

	TEST(DxfParserTests, get_bounding_box_should_do)
	{
		Line2D line(glm::vec2(-10, -10), glm::vec2(10, 10));
		auto boundingBox = line.get_bounding_box();
		EXPECT_GT(boundingBox.min_x, -11.0);
		EXPECT_GT(boundingBox.min_y, -11.0);
		EXPECT_LT(boundingBox.max_x, 11.0);
		EXPECT_LT(boundingBox.max_y, 11.0);

		auto start_angle = 90 * glm::pi<float>() / 180;
		auto end_angle = 180 * glm::pi<float>() / 180;
		Arc2D arc(glm::vec2(0, 0), 10, start_angle, end_angle);
		boundingBox = arc.get_bounding_box();
		EXPECT_GT(boundingBox.min_x, -11.0);
		EXPECT_GT(boundingBox.min_y, -1.0);
		EXPECT_LT(boundingBox.max_x, 1.0);
		EXPECT_LT(boundingBox.max_y, 11.0);

		// clock-wise
		Arc2D arc2(glm::vec2(0, 0), 10, start_angle, end_angle, false);
		boundingBox = arc2.get_bounding_box();
		EXPECT_GT(boundingBox.min_x, -11.0);
		EXPECT_GT(boundingBox.min_y, -11.0);
		EXPECT_LT(boundingBox.max_x, 11.0);
		EXPECT_LT(boundingBox.max_y, 11.0);

		Circle2D circle(glm::vec2(0, 0), 10);
		boundingBox = circle.get_bounding_box();
		EXPECT_GT(boundingBox.min_x, -11.0);
		EXPECT_GT(boundingBox.min_y, -11.0);
		EXPECT_LT(boundingBox.max_x, 11.0);
		EXPECT_LT(boundingBox.max_y, 11.0);

		vector vertices{
			glm::vec2(-10, -10),
			glm::vec2(10, 0),
			glm::vec2(20, 10),
			glm::vec2(20, -15),
		};
		PolyLine2D polyline(vertices);
		boundingBox = polyline.get_bounding_box();
		EXPECT_GT(boundingBox.min_x, -11.0);
		EXPECT_GT(boundingBox.min_y, -16.0);
		EXPECT_LT(boundingBox.max_x, 21.0);
		EXPECT_LT(boundingBox.max_y, 11.0);
	}
}
