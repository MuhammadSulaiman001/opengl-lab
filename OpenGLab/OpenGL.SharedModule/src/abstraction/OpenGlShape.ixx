module; // optional. Defines the beginning of the global module fragment

// #include directives go here but only apply to this file.
// import statements aren't allowed here. They go in the module preamble, below.

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>

export module OpenGlShape;

using namespace std;

export class OpenGlShape
{
	unsigned int VBO_, VAO_;
	GLenum drawing_mode_;
	vector<glm::vec3> vertices_;
	OpenGlShape(); // using empty ctor is not allowed

public:
	OpenGlShape(vector<glm::vec3>, GLenum);
	~OpenGlShape();
	unsigned int get_vao();
	GLenum get_drawing_mode();
	int get_data_size();
};