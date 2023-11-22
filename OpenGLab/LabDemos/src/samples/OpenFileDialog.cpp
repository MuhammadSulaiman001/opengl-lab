// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <ImGuiFileDialog.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <spdlog/spdlog.h>

module Sample;

namespace OpenFileDialog
{
	void setup_ImGUI(GLFWwindow* window);
	void render_ImGui();
	void shutdown_ImGui();

	int main()
	{
		glfwInit();

		GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
		glfwMakeContextCurrent(window);
		gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

		setup_ImGUI(window);

		while (!glfwWindowShouldClose(window))
		{
			glfwPollEvents();

			if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(window, true);

			// 1. Create the UI (inner window)
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();
			ImGui::Begin("My Control panel");
			ImGui::SetWindowSize(ImVec2(300, ImGui::GetWindowSize().y));
			if (ImGui::Button("Choose Image File"))
				// Create FileDialog instance
				ImGuiFileDialog::Instance()->
				OpenDialog("ChooseFileDlgKey", "Choose File", ".png", ".");

			// Show it
			if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey"))
			{
				// Action if OK
				if (ImGuiFileDialog::Instance()->IsOk())
				{
					auto filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
					auto filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
					// do something with the file
					spdlog::info("Selected file path = " + filePath);
					spdlog::info("Selected file name = " + filePathName);
				}

				ImGuiFileDialog::Instance()->Close();
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
