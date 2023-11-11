// optional #include or import statements. These only apply to this file
// imports in the associated module's interface are automatically available to this file

#include <GLFW/glfw3.h>

#include <iostream>

module Sample;

using namespace std;

namespace JustGlfwWindow
{
	int main()
	{
		glfwInit();
		GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
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
