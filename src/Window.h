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
			bool f_keys[GLFW_KEY_LAST];
			bool f_mouse[GLFW_MOUSE_BUTTON_LAST];
		public:
			Window(int width, int height, char *title, bool fulscreen);
			~Window();

			int getWidth();
			int getHeight();

			bool init();
			void update();
			void clear();
			bool close();

			friend void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
			friend void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
			friend void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	};

}
