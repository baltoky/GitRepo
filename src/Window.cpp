#include "Window.h"

namespace fission{

	Window::Window(){
		if(init() == -1){//Close the window if it returns '-1'
		}
	}
	
	int Window::init(){
		glewExperimental = GL_TRUE;
		if(glewInit() != GLEW_OK){
			std::cout << "Glew failed to initialize." << std::endl;
			return -1;
		}
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		window = glfwCreateWindow(f_width, f_height, f_title, NULL, NULL);

		if(window == 0){
			std::cout << "Failed to create window." << std::endl;
			glfwTerminate();
			return -1;
		}
		glfwMakeContextCurrent(window);
		return 1;
	}

}
