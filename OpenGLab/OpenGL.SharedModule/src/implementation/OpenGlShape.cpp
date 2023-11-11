// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>

module OpenGlShape;

using namespace std;

OpenGlShape::OpenGlShape(vector<glm::vec3> vertices, GLenum drawing_mode) : vertices_(vertices), drawing_mode_(drawing_mode)
{
	glGenVertexArrays(1, &VAO_);
	glGenBuffers(1, &VBO_);
	glBindVertexArray(VAO_);
	glBindBuffer(GL_ARRAY_BUFFER, VBO_);
	glBufferData(GL_ARRAY_BUFFER, vertices_.size() * sizeof(glm::vec3), vertices_.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

OpenGlShape::~OpenGlShape()
{
	glDeleteVertexArrays(1, &VAO_);
	glDeleteBuffers(1, &VBO_);
}

unsigned int OpenGlShape::get_vao() { return VAO_; }
GLenum OpenGlShape::get_drawing_mode() { return drawing_mode_; }
int OpenGlShape::get_data_size() { return vertices_.size(); }
