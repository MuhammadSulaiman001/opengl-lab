// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

module SharedModule;

void setup_ImGUI(GLFWwindow* window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGui::StyleColorsLight();
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();
}

void render_ImGui()
{
	glClear(GL_COLOR_BUFFER_BIT); // very important
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void shutdown_ImGui()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

// todo unit test
std::vector<float> read_float_array_from_file(const char* filename)
{
	std::vector<float> result;

	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << filename << std::endl;
		return result;
	}

	float value;
	while (file >> value) {
		result.push_back(value);
	}

	file.close();
	return result;
}
