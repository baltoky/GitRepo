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

	GLFWwindow* Window::getWindowPointer(){
		return f_window;
	}
	
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->f_keys[key] = action != GLFW_RELEASE;
	}

	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods){
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->f_mouse[button] = action != GLFW_RELEASE;
	}

	void cursor_position_callback(GLFWwindow* window, double xpos, double ypos){
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		win->f_xpos = xpos;
		win->f_ypos = ypos;
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

		if(f_fulscreen)
			glfwSetWindowMonitor(f_window, glfwGetPrimaryMonitor(), 0, 0, f_width, f_height, GLFW_REFRESH_RATE);

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

		glfwSetKeyCallback(f_window, key_callback);
		glfwSetMouseButtonCallback(f_window, mouse_button_callback);
		glfwSetCursorPosCallback(f_window, cursor_position_callback);
		
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

	bool Window::isKeyPressed(unsigned int keycode)const{
		if(keycode >= GLFW_KEY_LAST)
			return false;
		else
			return f_keys[keycode];
	}

	bool Window::isMouseButtonPressed(unsigned int button)const{
		if(button >= GLFW_MOUSE_BUTTON_LAST)
			return false;
		else
			return f_mouse[button];
	}

	void Window::getCursorPosition(double &xpos, double &ypos)const{
		xpos = this->f_xpos;
		ypos = this->f_ypos;
	}


}
