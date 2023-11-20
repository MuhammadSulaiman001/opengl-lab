// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <GLFW/glfw3.h>

#include <iostream>

module Sample;

using namespace std;

extern const int SCR_WIDTH;
extern const int SCR_HEIGHT;

namespace JustGlfwWindow
{
	int main()
	{
		glfwInit();
		GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
		glfwMakeContextCurrent(window);
		while (!glfwWindowShouldClose(window))
		{
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		glfwTerminate();
		return 0;
	}
}
