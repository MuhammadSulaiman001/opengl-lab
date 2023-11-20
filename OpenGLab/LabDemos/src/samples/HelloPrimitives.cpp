// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <learnopengl/shader_m.h>

import OpenGlShape;
import Drawer;

module Sample;

using namespace std;

extern const int SCR_WIDTH;
extern const int SCR_HEIGHT;

namespace HelloPrimitives
{
	vector<glm::vec3> shift(vector<glm::vec3> vertices, glm::vec3 offset)
	{
		for (auto& vertex : vertices) vertex = vertex + offset;
		return vertices;
	}

	Drawer drawer;

	int main()
	{
		glfwInit();
		GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
		glfwMakeContextCurrent(window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		Shader ourShader("./shaders/vs/bypass.vs", "./shaders/fs/red.fs");

		const vector data{
			glm::vec3(-0.10f, -0.25f, 0.0f), // bottom-left
			glm::vec3(0.10f, -0.25f, 0.0f), // bottom-right
			glm::vec3(0.10f, 0.25f, 0.0f), // top-right
			glm::vec3(-0.10f, 0.25f, 0.0f), // top-left
		};

		auto triangle_data = shift(data, glm::vec3(-0.80, 0, 0));
		triangle_data.pop_back(); // remove the forth point from the data
		OpenGlShape triangle(triangle_data, GL_TRIANGLES);

		auto rectangle_data = shift(data, glm::vec3(-0.50, 0, 0));
		OpenGlShape rectangle(rectangle_data, GL_TRIANGLE_FAN); // GL_QUADS is deprecated

		auto separated_lines_data = shift(data, glm::vec3(-0.20, 0, 0));
		OpenGlShape separated_lines(separated_lines_data, GL_LINES);

		auto connected_lines_data = shift(data, glm::vec3(0.10, 0, 0));
		OpenGlShape connected_lines(connected_lines_data, GL_LINE_STRIP);

		auto solo_points_data = shift(data, glm::vec3(0.40, 0, 0));
		OpenGlShape solo_points(solo_points_data, GL_POINTS);

		while (!glfwWindowShouldClose(window))
		{
			// Render
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			ourShader.use();

			drawer.draw(triangle);
			drawer.draw(rectangle);
			drawer.draw(separated_lines);
			drawer.draw(connected_lines);
			glPointSize(4);
			drawer.draw(solo_points);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwTerminate();
		return 0;
	}
}
