// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <learnopengl/shader_m.h>

module Sample;

using namespace std;

extern const int SCR_WIDTH;
extern const int SCR_HEIGHT;

namespace One_VAO_Two_Textures
{
	struct Vertex
	{
		glm::vec3 position;
		glm::vec2 textureCoords;
	};

	vector<Vertex> vertices{
		{glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0f, 0.0f)},
		{glm::vec3(0.5f, -0.5f, 0.0f), glm::vec2(1.0f, 0.0f)},
		{glm::vec3(0.5f, 0.5f, 0.0f), glm::vec2(1.0f, 1.0f)},
		{glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec2(0.0f, 1.0f)}
	};

	int main()
	{
		glfwInit();
		GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
		glfwMakeContextCurrent(window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		// 1. Prepare VBO, VAO
		unsigned int VBO, VAO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

		// position attribute
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		// texture attribute
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		stbi_set_flip_vertically_on_load(true);

		// 2. Load first texture
		unsigned int texture1;
		glGenTextures(1, &texture1);
		glBindTexture(GL_TEXTURE_2D, texture1);
		int width, height, nrChannels;
		unsigned char* data = stbi_load("./resources/container.jpg", &width, &height, &nrChannels, 0);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(data);

		// 3. Load second texture
		unsigned int texture2;
		glGenTextures(1, &texture2);
		glBindTexture(GL_TEXTURE_2D, texture2);
		data = stbi_load("./resources/awesomeface.png", &width, &height, &nrChannels, 0);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(data);

		// pass data to shader program
		Shader ourShader("./shaders/vs/transform.vs", "./shaders/fs/accept-1-texture.fs");
		ourShader.use();
		glm::mat4 view = glm::mat4(1.0f);
		view = glm::translate(view, glm::vec3(.0f, .0f, -2.0f));
		glm::mat4 projection = glm::perspective(
			glm::radians(45.0f),
			(float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		ourShader.setMat4("projection", projection);
		ourShader.setMat4("view", view);

		// bind VAO, only once, because we want to use the same data fed to GPU..
		glBindVertexArray(VAO);

		while (!glfwWindowShouldClose(window))
		{
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);

			// use first texture
			glBindTexture(GL_TEXTURE_2D, texture1);
			glm::mat4 model = glm::mat4(1.0f);
			model = translate(model, glm::vec3(-.6f, .0f, .0f));
			ourShader.setMat4("model", model);
			glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size());

			// use second texture 
			glBindTexture(GL_TEXTURE_2D, texture2);
			model = glm::mat4(1.0f); // reset to identity matrix
			model = translate(model, glm::vec3(.6f, .0f, .0f));
			ourShader.setMat4("model", model);
			glDrawArrays(GL_TRIANGLE_FAN, 0, vertices.size());

			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);

		glfwTerminate();
		return 0;
	}
}
