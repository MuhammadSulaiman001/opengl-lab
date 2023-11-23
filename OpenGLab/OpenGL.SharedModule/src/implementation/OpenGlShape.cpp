// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <stdexcept>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>

import SharedModule;

module OpenGlShape;

using namespace std;

OpenGlShape::OpenGlShape(const vector<glm::vec3>& vertices, GLenum drawing_mode)
	: number_of_vertices_(vertices.size()), drawing_mode_(drawing_mode)
{
	glGenVertexArrays(1, &VAO_);
	glGenBuffers(1, &VBO_);
	glBindVertexArray(VAO_);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_);
	glBufferData(GL_ARRAY_BUFFER, number_of_vertices_ * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

vector<glm::vec3> convert_floats_to_vec3(const vector<float>& vertices);

OpenGlShape::OpenGlShape(const vector<float>& vertices, GLenum drawing_mode)
	: OpenGlShape(convert_floats_to_vec3(vertices), drawing_mode)
{
}

OpenGlShape::~OpenGlShape()
{
	glDeleteVertexArrays(1, &VAO_);
	glDeleteBuffers(1, &VBO_);
}

unsigned int OpenGlShape::get_vao() { return VAO_; }
GLenum OpenGlShape::get_drawing_mode() { return drawing_mode_; }
int OpenGlShape::get_number_of_vertices() { return number_of_vertices_; }

struct Vertex
{
	glm::vec3 position;
	glm::vec2 texture_coords;
};

OpenGlTextureShape::OpenGlTextureShape(const vector<glm::vec3>& positions, GLenum mode,
                                       const char* texture_path, const vector<glm::vec2>& texture_coords)
	: OpenGlShape(positions, mode)
{
	if (positions.size() != texture_coords.size())
	{
		throw exception("positions list and coords list should have the same count of data!");
	}
	// Create a vector of interleaved vertices
	vector<Vertex> vertices;
	for (size_t i = 0; i < positions.size(); ++i)
		vertices.push_back({positions[i], texture_coords[i]});

	glGenVertexArrays(1, &VAO_);
	glGenBuffers(1, &VBO_);
	glBindVertexArray(VAO_);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// texture attribute
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	texture_id_ = load_texture(texture_path);
}

tuple<vector<glm::vec3>, vector<glm::vec2>> convert_floats_to_vec3_and_vec2(const vector<float>& vertices);

OpenGlTextureShape::OpenGlTextureShape(const vector<float>& vertices, GLenum mode,
                                       const char* texture_path)
	: OpenGlTextureShape(get<0>(convert_floats_to_vec3_and_vec2(vertices)), mode,
	                     texture_path, get<1>(convert_floats_to_vec3_and_vec2(vertices)))
{
}

OpenGlTextureShape::~OpenGlTextureShape()
{
	glDeleteTextures(1, &texture_id_);
}

unsigned int OpenGlTextureShape::get_texture_id()
{
	return texture_id_;
}

vector<glm::vec3> convert_floats_to_vec3(const vector<float>& vertices)
{
	vector<glm::vec3> result;
	for (int i = 0; i < vertices.size() / 3; ++i)
	{
		glm::vec3 pos(vertices[i * 5], vertices[i * 5 + 1], vertices[i * 5 + 2]);
		result.push_back(pos);
	}
	return result;
}

tuple<vector<glm::vec3>, vector<glm::vec2>> convert_floats_to_vec3_and_vec2(
	const vector<float>& vertices)
{
	vector<glm::vec3> positions;
	vector<glm::vec2> textureCoords;

	// Ensure that the size of 'vertices' is a multiple of 5 (3 for position, 2 for texture coords)
	if (vertices.size() % 5 != 0)
	{
		throw runtime_error("Invalid vertices data size");
	}

	// Iterate through the flat vector and populate separate vectors
	for (size_t i = 0; i < vertices.size(); i += 5)
	{
		glm::vec3 position(vertices[i], vertices[i + 1], vertices[i + 2]);
		glm::vec2 textureCoord(vertices[i + 3], vertices[i + 4]);

		positions.push_back(position);
		textureCoords.push_back(textureCoord);
	}

	return make_tuple(positions, textureCoords);
}
