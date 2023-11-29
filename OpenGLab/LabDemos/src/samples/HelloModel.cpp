// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stb_image.h>
#include <glm/vec3.hpp>
#include <learnopengl/camera.h>
#include <learnopengl/shader.h>
#include <learnopengl/model.h>

module Sample;

using namespace std;

extern const int SCR_WIDTH;
extern const int SCR_HEIGHT;

namespace HelloModel
{
	void mouse_callback(GLFWwindow* window, double xpos, double ypos);
	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	void processInput(GLFWwindow* window);

	Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
	float lastX = SCR_WIDTH / 2.0f;
	float lastY = SCR_HEIGHT / 2.0f;
	bool firstMouse = true;

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	int main()
	{
		glfwInit();
		GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
		glfwMakeContextCurrent(window);
		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		glfwSetCursorPosCallback(window, mouse_callback);
		glfwSetScrollCallback(window, scroll_callback);

		stbi_set_flip_vertically_on_load(true);

		glEnable(GL_DEPTH_TEST);

		Shader ourShader("./shaders/vs/transform.vs", "./shaders/fs/accept-1-texture.fs");

		Model ourModel("./resources/models/rock/rock.obj");

		while (!glfwWindowShouldClose(window))
		{
			processInput(window);

			const auto currentFrame = static_cast<float>(glfwGetTime());
			deltaTime = currentFrame - lastFrame;
			lastFrame = currentFrame;

			glClearColor(0.05f, 0.05f, 0.05f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			ourShader.use();

			glm::mat4 projection = glm::perspective(
				glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
			glm::mat4 view = camera.GetViewMatrix();
			ourShader.setMat4("projection", projection);
			ourShader.setMat4("view", view);

			// rock1
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.0f, -2.0f, -10.0f));
			ourShader.setMat4("model", model);
			ourModel.Draw(ourShader);

			// rock2
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(0.0f, 2.0f, -10.0f));
			ourShader.setMat4("model", model);
			ourModel.Draw(ourShader);

			// rock3
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(-2.0f, 0.0f, -10.0f));
			ourShader.setMat4("model", model);
			ourModel.Draw(ourShader);

			// rock4
			model = glm::mat4(1.0f);
			model = glm::translate(model, glm::vec3(2.0f, 0.0f, -10.0f));
			ourShader.setMat4("model", model);
			ourModel.Draw(ourShader);

			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwTerminate();
		return 0;
	}

	void processInput(GLFWwindow* window)
	{
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(window, true);

		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			camera.ProcessKeyboard(FORWARD, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			camera.ProcessKeyboard(BACKWARD, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			camera.ProcessKeyboard(LEFT, deltaTime);
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			camera.ProcessKeyboard(RIGHT, deltaTime);
	}

	void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
	{
		float xpos = static_cast<float>(xposIn);
		float ypos = static_cast<float>(yposIn);

		if (firstMouse)
		{
			lastX = xpos;
			lastY = ypos;
			firstMouse = false;
		}

		float xoffset = xpos - lastX;
		float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

		lastX = xpos;
		lastY = ypos;

		camera.ProcessMouseMovement(xoffset, yoffset);
	}

	void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		camera.ProcessMouseScroll(static_cast<float>(yoffset));
	}
}
