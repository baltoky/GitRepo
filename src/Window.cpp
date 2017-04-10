#include "Window.h"

namespace fission{
	void windowResize(GLFWwindow* window, int width, int height);
	Window::Window(int width, int height, char *title, bool fulscreen){
		f_width = width;
		f_height = height;
		f_title = title;
		f_fulscreen = fulscreen;

		if(!init()){//Close the window if it returns '-1'
			std::cout << "The Window did not initiate correctly." << std::endl;
		}

		for(int i = 0; i < GLFW_KEY_LAST; i++){
			f_keys[i] = false;
		}

		for(int i = 0; i < GLFW_MOUSE_BUTTON_LAST; i++){
			f_mouse[i] = false;
		}
	}

	Window::~Window(){
		glfwDestroyWindow(f_window);
		glfwTerminate();
	}

	int Window::getWidth(){
		return f_width;
	}

	int Window::getHeight(){
		return f_height;
	}
	
	bool Window::init(){

		if(!glfwInit()){
			std::cout << "glfwInit() failed." << std::endl;
			return false;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		f_window = glfwCreateWindow(f_width, f_height, f_title, NULL, NULL);

		if(f_window == 0){
			std::cout << "Failed to create window." << std::endl;
			glfwDestroyWindow(f_window);
			glfwTerminate();
			return false;
		}

		glfwMakeContextCurrent(f_window);
		glfwSetWindowUserPointer(f_window, this);
		glfwSetWindowSizeCallback(f_window, windowResize);

		glewExperimental = GL_TRUE;
		if(glewInit() != GLEW_OK){
			std::cout << "Glew failed to initialize." << std::endl;
			return false;
		}
		
		return 1;
	}

	void windowResize(GLFWwindow* window, int width, int height){
		glViewport(0, 0, width, height);
	}

	void Window::update(){
		glfwPollEvents();
		glfwGetFramebufferSize(f_window, &f_width, &f_height);
		glfwSwapBuffers(f_window);
	}

	void Window::clear(){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	bool Window::close(){
		return glfwWindowShouldClose(f_window) == 1;
	}

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){

	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
	}

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
	}

}
