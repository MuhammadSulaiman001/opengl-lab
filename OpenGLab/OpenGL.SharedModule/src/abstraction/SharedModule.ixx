module; // optional. Defines the beginning of the global module fragment

// #include directives go here but only apply to this file.
// import statements aren't allowed here. They go in the module preamble, below.

#include <stdexcept>
#include <GLFW/glfw3.h>
#include <vector>

export module SharedModule;

export class NotImplementedException : public std::logic_error
{
public:
    NotImplementedException() : std::logic_error("Function not yet implemented") { };
};

export void setup_ImGUI(GLFWwindow* window);
export void render_ImGui();
export void shutdown_ImGui();

export std::vector<float> read_float_array_from_file(const char* filename);
export unsigned int load_texture(const char* filename);