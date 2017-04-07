#include <GLFW/glfw3.h>

int main(int argc, char **argv)
{
	GLFWwindow *window;

	//Initialize the library
	if(!glfwInit())
		return -1;

	//Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(640, 480, "HelloWorld", NULL, NULL);
	if(!window)
	{
		glfwTerminate();
		return -1;
	}

	//MAke the window's context current
	glfwMakeContextCurrent(window);

	//Loop until the user closes the window
	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
}
