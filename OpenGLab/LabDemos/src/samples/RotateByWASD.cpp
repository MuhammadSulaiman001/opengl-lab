// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <learnopengl/shader_m.h>

import OpenGlShape;
import Drawer;

module Sample;

using namespace std;

extern const int SCR_WIDTH;
extern const int SCR_HEIGHT;

namespace RotateByWASD
{
	Drawer drawer;

	void key_pressed_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

	glm::mat4 model(1.0f);
	glm::mat4 view(1.0f);
	glm::mat4 projection(1.0f);

	int main()
	{
		glfwInit();
		GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
		glfwMakeContextCurrent(window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		glfwSetKeyCallback(window, key_pressed_callback);
		Shader ourShader("./shaders/vs/transform-no-tex.vs", "./shaders/fs/red.fs");
		vector data{
			glm::vec3(-0.5f, -0.5f, 0.0f),
			glm::vec3(0.5f, -0.5f, 0.0f),
			glm::vec3(0.0f, 0.5f, 0.0f)
		};

		ourShader.use();
		ourShader.setMat4("view", view);
		ourShader.setMat4("projection", projection);

		OpenGlShape triangle(data, GL_TRIANGLES);
		while (!glfwWindowShouldClose(window))
		{
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);

			// Render
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			ourShader.setMat4("model", model);
			drawer.draw(triangle);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwTerminate();
		return 0;
	}

	void key_pressed_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		if (key == GLFW_KEY_W)
		{
			std::cout << "Up" << endl;
			model = glm::rotate(model, glm::radians(-5.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		}
		if (key == GLFW_KEY_S)
		{
			std::cout << "Down" << endl;
			model = glm::rotate(model, glm::radians(5.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		}
		if (key == GLFW_KEY_A)
		{
			std::cout << "Left" << endl;
			model = glm::rotate(model, glm::radians(5.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		}
		if (key == GLFW_KEY_D)
		{
			std::cout << "Right" << endl;
			model = glm::rotate(model, glm::radians(-5.0f), glm::vec3(0.0f, 0.0f, 1.0f));
		}
	}
}
