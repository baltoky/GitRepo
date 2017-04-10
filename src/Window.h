#pragma once

#define GLEW_STATIC
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace fission{

	class Window{
	
		private:
			int f_width;
			int f_height;
			GLFWwindow *window;
			char* title;
		public:
			Window();
			~Window();
			int init();
	};

}
