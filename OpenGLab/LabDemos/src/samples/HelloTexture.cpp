// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <stb_image.h>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <learnopengl/shader_s.h>

module Sample;

extern const int SCR_WIDTH;
extern const int SCR_HEIGHT;

namespace HelloTexture
{
	struct Vertex
	{
		glm::vec3 position;
		glm::vec2 textureCoords;
	};

	std::vector<Vertex> vertices;

	int main()
	{
		glfwInit();
		GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
		glfwMakeContextCurrent(window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		Shader ourShader("./shaders/vs/bypass-texture.vs", "./shaders/fs/accept-1-texture.fs");
		ourShader.use();

		vertices.push_back({glm::vec3(-0.5f, -0.5f, 0.0f), glm::vec2(0.0f, 0.0f)});
		vertices.push_back({glm::vec3(0.5f, -0.5f, 0.0f), glm::vec2(1.0f, 0.0f)});
		vertices.push_back({glm::vec3(0.5f, 0.5f, 0.0f), glm::vec2(1.0f, 1.0f)});
		vertices.push_back({glm::vec3(-0.5f, 0.5f, 0.0f), glm::vec2(0.0f, 1.0f)});

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

		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		int width, height, nrChannels;
		unsigned char* data = stbi_load("./resources/container.jpg", &width, &height, &nrChannels, 0);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
		stbi_image_free(data);

		while (!glfwWindowShouldClose(window))
		{
			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			// bind Texture
			glBindTexture(GL_TEXTURE_2D, texture);
			glBindVertexArray(VAO);
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
