module; // optional. Defines the beginning of the global module fragment

// #include directives go here but only apply to this file.
// import statements aren't allowed here. They go in the module preamble, below.

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>

export module OpenGlShape;

using namespace std;

// TODO, accept passing VBO in ctor!
export class OpenGlShape
{
	GLenum drawing_mode_;
	unsigned int number_of_vertices_;
	OpenGlShape(); //= delete; // using empty ctor is not allowed
protected:
	unsigned int VBO_, VAO_;

public:
	OpenGlShape(const vector<glm::vec3>&, GLenum);
	OpenGlShape(const vector<float>&, GLenum);
	~OpenGlShape();
	unsigned int get_vao();
	GLenum get_drawing_mode();
	int get_number_of_vertices();
};

// TODO, accept passing VBO in ctor!
export class OpenGlTextureShape : public OpenGlShape
{
private:
	unsigned int texture_id_;

public:

	OpenGlTextureShape(const vector<glm::vec3>&, GLenum,
		const char*, const vector<glm::vec2>&);
	OpenGlTextureShape(const vector<float>& vertices, GLenum mode,
	const char* texture_path);
	~OpenGlTextureShape();
	unsigned int get_texture_id();
};