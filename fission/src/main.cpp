#include "graphics/Window.h"
#include "graphics/shader/shader.h"
#include "graphics/image2D/Texture.h"
#include "graphics/image2D/GraphicsData.h"
#include "graphics/image2D/Renderable.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>

#define MANUAL_DATA 0

const int WIDTH = 1280;
const int HEIGHT = 720;

int main(int argc, char **argv)
{
	const char* title = (char*)"The Little RPG";
	const char* vertexShader = "./src/graphics/shader/defaultVert.glsl";
	const char* fragmentShader = "./src/graphics/shader/defaultFrag.glsl";

	fission::Window window(WIDTH, HEIGHT, (char*)title, true); // Initializes a window, which controls it's own input.

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	fission::ShaderProgram prog((char*)vertexShader, (char*)fragmentShader); // Creates a shader program, and links the shader.

	GLuint VAO1;
	glGenVertexArrays(1, &VAO1);

	fission::Renderable sprite(glm::vec2(0.0f, 0.0f), 0.5f, 0.5f, 0.0f);
	sprite.setTextureUV(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));

	fission::Texture2D tex("./img/SunwiredIcon.png");

	glBindVertexArray(VAO1);
		sprite.init();
		if(!tex.readTexture()){
			std::cout << "ERROR: reading texure in main.cpp" << std::endl;
		}
	glBindVertexArray(0);


	// -- End of the square graphics --
	prog.useProgram();

	glm::mat4 projectionMat; // Projection / Screen Matrix
	glm::mat4 viewMat; // View / Camera Matrix
	glm::mat4 modelMat; // Model / Object Matrix

	modelMat = glm::scale(modelMat, glm::vec3(10.0f, 10.0f, 0.0f));
	modelMat = glm::translate(modelMat, glm::vec3(0.0f, 0.0f, 5.0f));
	viewMat = glm::translate(viewMat, glm::vec3(0.0f, 0.0f, -5.0f));
 	projectionMat= glm::perspective(glm::radians(90.0f), (GLfloat)WIDTH / (GLfloat)HEIGHT, 1.0f, 100.0f);

	GLuint projectionLocation = glGetUniformLocation(prog.f_program, "Projection");
	GLuint viewLocation = glGetUniformLocation(prog.f_program, "View");
	GLuint modelLocation = glGetUniformLocation(prog.f_program, "Model");

	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projectionMat));

	while(!window.close()){
		window.clear();

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

		if(window.isKeyPressed(GLFW_KEY_ESCAPE))
			glfwSetWindowShouldClose(window.getWindowPointer(), true);

		if(window.isKeyPressed(GLFW_KEY_UP))
			modelMat = glm::rotate(modelMat, glm::radians(5.0f), glm::vec3(0.0f, 0.0f, 0.0001f));

		glBindVertexArray(VAO1);
		tex.bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		tex.unbind();

		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelMat)); // Model to the Shader.
		glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(viewMat)); // View to the Shader.

		window.update();
	}
}
