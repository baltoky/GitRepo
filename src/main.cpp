#include "Window.h"

const int WIDTH = 1280;
const int HEIGHT = 720;

int main(int argc, char **argv)
{
	char* title = (char*)"The Little RPG";
	fission::Window window(WIDTH, HEIGHT, title, false);

	while(!window.close()){
		window.update();
		if(window.isKeyPressed(GLFW_KEY_ENTER))
			glfwSetWindowShouldClose(window.getWindowPointer(), true);
	}
}
