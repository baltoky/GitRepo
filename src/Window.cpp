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
	}

}
