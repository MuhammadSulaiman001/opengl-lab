#include <exception>
#include <cassert>
#include <memory>
#include "DxfParser.h"
#include "../libdxfrw/dx_interface.h"

using namespace std;

vector<unique_ptr<Entity2D>> convert_drw_entities_to_entities2d(const list<DRW_Entity*>& list);

vector<unique_ptr<Entity2D>> DxfParser::get_entities()
{
	dx_data fData;
	auto input = new dx_iface();
	auto is_ok = input->fileImport(dxf_file_path_, &fData, false);
	assert(is_ok);
	list<DRW_Entity*> drw_entities = fData.mBlock->ent;
	assert(drw_entities.size() > 0);
	vector<unique_ptr<Entity2D>> result = convert_drw_entities_to_entities2d(drw_entities);
	return result;
}

BoundingBox DxfParser::get_bounding_box(vector<unique_ptr<Entity2D>>& entities)
{
	auto minX = numeric_limits<float>::max();
	auto minY = numeric_limits<float>::max();
	auto maxX = numeric_limits<float>::min();
	auto maxY = numeric_limits<float>::min();

	for (const auto& entity : entities)
	{
		auto entity_bounding_box = entity.get()->get_bounding_box();
		if (entity_bounding_box.min_x < minX)
			minX = entity_bounding_box.min_x;
		if (entity_bounding_box.min_y < minY)
			minY = entity_bounding_box.min_y;
		if (entity_bounding_box.max_x > maxX)
			maxX = entity_bounding_box.max_x;
		if (entity_bounding_box.max_y > maxY)
			maxY = entity_bounding_box.max_y;
	}
	return BoundingBox(minX, minY, maxX, maxY);
}

glm::vec2 convert_drw_coord_to_vec2(const DRW_Coord& drw_coord)
{
	return glm::vec2(drw_coord.x, drw_coord.y);
}

vector<unique_ptr<Entity2D>> convert_drw_entities_to_entities2d(const list<DRW_Entity*>& list)
{
	vector<unique_ptr<Entity2D>> result;
	for (DRW_Entity* entity : list)
	{
		if (entity->eType == DRW::LINE)
		{
			auto line = static_cast<DRW_Line*>(entity);
			auto start_point = convert_drw_coord_to_vec2(line->basePoint);
			auto end_point = convert_drw_coord_to_vec2(line->secPoint);
			auto line2d = Line2D(start_point, end_point);
			result.push_back(std::make_unique<Line2D>(line2d));
		}
		else if (entity->eType == DRW::ARC)
		{
			const auto arc = static_cast<DRW_Arc*>(entity);
			auto center = convert_drw_coord_to_vec2(arc->basePoint);
			auto arc2d = Arc2D(center, arc->radious, arc->staangle, arc->endangle, arc->isccw);
			result.push_back(std::make_unique<Arc2D>(arc2d));
		}
		else if (entity->eType == DRW::CIRCLE)
		{
			const auto circle = static_cast<DRW_Circle*>(entity);
			auto center = convert_drw_coord_to_vec2(circle->basePoint);
			auto circle2d = Circle2D(center, circle->radious);
			result.push_back(std::make_unique<Circle2D>(circle2d));
		}
		else if (entity->eType == DRW::LWPOLYLINE)
		{
			const auto polyline = static_cast<DRW_LWPolyline*>(entity);
			vector<glm::vec2> glm_vertices;
			for (auto vertex_2d : polyline->vertlist)
			{
				auto polyline_vertex = vertex_2d.get();
				// We won't consider polyline with bulge
				assert(polyline_vertex->bulge == 0.0);
				glm_vertices.push_back(glm::vec2(polyline_vertex->x, polyline_vertex->y));
			}
			auto polyLine2D = PolyLine2D(glm_vertices);
			result.push_back(std::make_unique<PolyLine2D>(polyLine2D));
		}
	}
	return result;
}

