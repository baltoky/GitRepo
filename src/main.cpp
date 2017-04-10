#include "Window.h"

const int WIDTH = 500;
const int HEIGHT = 300;

int main(int argc, char **argv)
{
	char* title = (char*)"The Little RPG";
	fission::Window window(WIDTH, HEIGHT, title, false);

	while(!window.close()){
		window.update();
	}
}
