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
			GLFWwindow* f_window;
			char* f_title;
			bool f_fulscreen;
		public:
			Window(int width, int height, char *title, bool fulscreen);
			~Window();
			int getWidth();
			int getHeight();
			bool init();
			void update();
			void clear();
			bool close();
	};

}
