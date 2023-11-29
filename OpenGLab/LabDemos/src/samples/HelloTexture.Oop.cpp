// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <learnopengl/shader_s.h>

import OpenGlShape;
import Drawer;

module Sample;

extern const int SCR_WIDTH;
extern const int SCR_HEIGHT;

namespace HelloTexture_Oop
{
	Drawer drawer;

	int main()
	{
		glfwInit();
		GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
		glfwMakeContextCurrent(window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		Shader ourShader("./shaders/vs/bypass-texture.vs", "./shaders/fs/accept-1-texture.fs");
		ourShader.use();

		std::vector positions{
			glm::vec3(-0.5f, -0.5f, 0.0f),
			glm::vec3(0.5f, -0.5f, 0.0f),
			glm::vec3(0.5f, 0.5f, 0.0f),
			glm::vec3(-0.5f, 0.5f, 0.0f),
		};

		std::vector texture_coords{
			glm::vec2(0.0f, 0.0f),
			glm::vec2(1.0f, 0.0f),
			glm::vec2(1.0f, 1.0f),
			glm::vec2(0.0f, 1.0f)
		};

		OpenGlShapeWithTexture shape(positions, GL_TRIANGLE_FAN, "./resources/container.jpg", texture_coords);

		while (!glfwWindowShouldClose(window))
		{
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			drawer.draw(shape);

			glfwPollEvents();
			glfwSwapBuffers(window);
		}

		glfwTerminate();
		return 0;
	}
}
