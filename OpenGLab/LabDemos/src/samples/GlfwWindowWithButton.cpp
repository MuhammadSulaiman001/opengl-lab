// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

module Sample;

extern const int SCR_WIDTH;
extern const int SCR_HEIGHT;

namespace GlfwWindowWithButton
{
	void setup_ImGUI(GLFWwindow* window);
	void render_ImGui();
	void shutdown_ImGui();

	int main()
	{
		glfwInit();

		GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
		glfwMakeContextCurrent(window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		setup_ImGUI(window);

		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();

			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);

			// 1. Create panel UI (inner window)
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();
			ImGui::Begin("My Control panel");
			if (ImGui::Button("Click Me!"))
			{
				// do something when button clicked...
			}

			ImGui::SameLine();
			ImGui::End();
			render_ImGui();

			// 2. Draw OpenGL Scene

			glfwSwapBuffers(window);
		}

		shutdown_ImGui();

		glfwTerminate();
		return 0;
	}

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
}
