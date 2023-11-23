// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/fwd.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/matrix.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <learnopengl/shader_m.h>

import OpenGlShape;
import Drawer;

module Sample;

extern const int SCR_WIDTH;
extern const int SCR_HEIGHT;

namespace HelloTexture_Transparency
{
	Drawer drawer;

	int main()
	{
		glfwInit();
		GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
		glfwMakeContextCurrent(window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		Shader ourShader("./shaders/vs/transform.vs", "./shaders/fs/accept-1-texture.fs");
		ourShader.use();
		glm::mat4 view(1.0f);
		glm::mat4 projection(1.0f);
		ourShader.setMat4("view", view);
		ourShader.setMat4("projection", projection);

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

		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		OpenGlTextureShape shape(positions, GL_TRIANGLE_FAN, "./resources/awesomeface.png", texture_coords);

		while (!glfwWindowShouldClose(window))
		{
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glm::mat4 model(1.0f);
			model = glm::scale(model, glm::vec3(.5f));
			model = glm::translate(model, glm::vec3(1.0f, 0.0f, 0.0f));
			ourShader.setMat4("model", model);
			glEnable(GL_BLEND);
			drawer.draw(shape);

			model = glm::translate(model, glm::vec3(-2.0f, 0.0f, 0.0f));
			ourShader.setMat4("model", model);
			glDisable(GL_BLEND);
			drawer.draw(shape); // draw again

			glfwPollEvents();
			glfwSwapBuffers(window);
		}

		glfwTerminate();
		return 0;
	}
}
