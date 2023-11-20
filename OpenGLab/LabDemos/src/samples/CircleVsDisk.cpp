// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <glm/ext/scalar_constants.hpp>
#include <learnopengl/shader_m.h>

import OpenGlShape;
import Drawer;

module Sample;

using namespace std;

extern const int SCR_WIDTH;
extern const int SCR_HEIGHT;

namespace CircleVsDisk
{
	std::vector<glm::vec3> create_circle_points(glm::vec3 center, float radius, int num_of_segments);
	vector<glm::vec3> shift(vector<glm::vec3> vertices, glm::vec3 offset);

	Drawer drawer;

	int main()
	{
		glfwInit();
		GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
		glfwMakeContextCurrent(window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		Shader ourShader("./shaders/vs/bypass.vs", "./shaders/fs/red.fs");

		auto center = glm::vec3(0, 0, 0);
		auto radius = 0.25f;
		auto num_of_segments = 120;

		auto circle1_vertices = create_circle_points(center, radius, num_of_segments);
		auto shift_offset = glm::vec3(-0.5, 0, 0);
		circle1_vertices = shift(circle1_vertices, shift_offset);
		OpenGlShape circle(circle1_vertices, GL_LINE_STRIP);

		auto circle2_vertices = create_circle_points(center, radius, num_of_segments);
		shift_offset = glm::vec3(0.5, 0, 0);
		circle2_vertices = shift(circle2_vertices, shift_offset);
		// We'll use GL_TRIANGLE_FAN mode to draw a disk, so we need to put the center of the fan as first point
		circle2_vertices.insert(circle2_vertices.begin(), center + shift_offset);
		OpenGlShape disk(circle2_vertices, GL_TRIANGLE_FAN);

		while (!glfwWindowShouldClose(window))
		{
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);

			// Render
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			ourShader.use();

			drawer.draw(circle);
			drawer.draw(disk);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwTerminate();
		return 0;
	}

	std::vector<glm::vec3> create_circle_points(glm::vec3 center, float radius, int num_of_segments)
	{
		std::vector<glm::vec3> circlePoints;
		auto aspect_ratio = static_cast<float>(SCR_WIDTH) / static_cast<float>(SCR_HEIGHT);

		for (int i = 0; i <= num_of_segments; i++)
		{
			// the first theta will be 0, the last theta will be 2*PI
			auto theta = (static_cast<float>(i) / num_of_segments) * (2.0f * glm::pi<float>());
			auto x = center.x + radius * glm::cos(theta);
			auto y = center.y + radius * glm::sin(theta);
			circlePoints.push_back(glm::vec3(x, y * aspect_ratio, center.z));
		}

		return circlePoints;
	}

	vector<glm::vec3> shift(vector<glm::vec3> vertices, glm::vec3 offset)
	{
		for (auto& vertex : vertices) vertex = vertex + offset;
		return vertices;
	}
}
