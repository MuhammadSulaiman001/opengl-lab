// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <stb_image.h>
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
	if (!file.is_open())
	{
		std::cerr << "Error opening file: " << filename << std::endl;
		return result;
	}

	float value;
	while (file >> value)
	{
		result.push_back(value);
	}

	file.close();
	return result;
}

unsigned int load_texture(const char* texture_path)
{
	unsigned int texture_id;
	glGenTextures(1, &texture_id);
	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(texture_path, &width, &height, &nrChannels, 0);
	GLenum image_format;
	if (nrChannels == 1)
		image_format = GL_RED;
	else if (nrChannels == 3)
		image_format = GL_RGB;
	else if (nrChannels == 4)
		image_format = GL_RGBA;
	glBindTexture(GL_TEXTURE_2D, texture_id);
	/*
	 * 	glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		-----------
		GL_RGB Changed to GL_RGBA
		this will show transparent texls
	 */
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, image_format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	stbi_image_free(data);
	return texture_id;
}
