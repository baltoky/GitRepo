#include "Window.h"

const int WIDTH = 1280;
const int HEIGHT = 720;

int main(int argc, char **argv)
{
	char* title = (char*)"The Little RPG";
	fission::Window window(WIDTH, HEIGHT, title, false);

	while(!window.close()){
		window.clear();

		glClearColor(0.667f, 0.224f, 0.224f, 1.0f);

		if(window.isKeyPressed(GLFW_KEY_ESCAPE))
			glfwSetWindowShouldClose(window.getWindowPointer(), true);

		window.update();
	}
}
