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

namespace HelloTriangle_Oop
{
	Drawer drawer;
	int main()
	{
		glfwInit();
		GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
		glfwMakeContextCurrent(window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		Shader ourShader("./shaders/vs/bypass.vs", "./shaders/fs/red.fs");
		vector data {
				glm::vec3(-0.5f, -0.5f, 0.0f),
				glm::vec3(0.5f, -0.5f, 0.0f),
				glm::vec3(0.0f, 0.5f, 0.0f)
		};

		OpenGlShape triangle(data, GL_TRIANGLES);
		while (!glfwWindowShouldClose(window))
		{
			// Render
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			ourShader.use();
			drawer.draw(triangle);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwTerminate();
		return 0;
	}
}
