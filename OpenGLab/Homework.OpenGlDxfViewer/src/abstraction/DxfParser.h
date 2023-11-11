#pragma once
#include <string>
#include <exception>
#include <memory>

#include "Entity2D.h"

class DxfParser
{
	string dxf_file_path_;
public:
	DxfParser(const string& dxf_file_path)
	{
		if (!dxf_file_path.ends_with(".dxf"))
			throw exception("Not a dxf file");
		dxf_file_path_ = dxf_file_path;
	}

	BoundingBox get_bounding_box(vector<unique_ptr<Entity2D>>& entities);
	vector<unique_ptr<Entity2D>> get_entities();
};

// Issue solved: this header is in .exe app, so the implementation is not in a .lib file
// so, to consume this code in gtest ptoject, I've added the path to Temp directory (location of .obj files) + .obj file name to the linker (see linker props of this project)
// TODO: use https://github.com/k06a/boolinq to replace this method
template <typename TBase, typename TDerived>
std::vector<std::unique_ptr<TDerived>> filter(const std::vector<std::unique_ptr<TBase>>& entities)
{
	std::vector<std::unique_ptr<TDerived>> result;

	for (const auto& entity : entities)
	{
		if (typeid(*entity) == typeid(TDerived))
			result.push_back(std::make_unique<TDerived>(*dynamic_cast<TDerived*>(entity.get())));
	}

	return result;
}
