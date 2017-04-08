#pragma once

#include <GL\glew.h>
#include <GLFW\glfw3.h>

namespace fission{

	class window{
	
		private:
			int f_width;
			int f_height;
			GLFWwindow *window;
			char* title;
		public:
			window();
			~window();
	}

}
