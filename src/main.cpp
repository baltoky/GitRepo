#include "graphics/Window.h"
#include "graphics/shader/shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>

const int WIDTH = 1280;
const int HEIGHT = 720;

int main(int argc, char **argv)
{
	const char* title = (char*)"The Little RPG";
	const char* vertexShader = "./src/graphics/shader/defaultVert.glsl";
	const char* fragmentShader = "./src/graphics/shader/defaultFrag.glsl";

	fission::Window window(WIDTH, HEIGHT, (char*)title, false); // Initializes a window, which controls it's own input.

	fission::ShaderProgram prog((char*)vertexShader, (char*)fragmentShader); // Creates a shader program, and links the shader.

	// -- Starts organizing the triangle graphics -- 
#if 0
	GLfloat vert[] = {
		// Vetices.			// Colors.
		-0.7f, 0.0f, 0.0f,		0.294f, 0.745f, 0.808f,
		-0.1f, 0.0f, 0.0f,		1.0f, 0.071f, 0.431f,
		-0.4f, 0.3f, 0.0f,		0.482f, 0.929f, 0.0f
	};

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	GLuint VBO;
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

	glBindVertexArray(0);
	// -- End of the triangle graphics --
#endif

#if 1
	// -- Start of the square graphics -- 
	GLfloat sqrVert[] = {
		// Vertices, 		
		-0.5f, 0.5f, 0.0f, 	0.8f, 0.5f, 0.2f,
		-0.5f, -0.5f, 0.0f,	0.5f, 0.2f, 0.8f,
		0.5f, 0.5f, 0.0f,	0.5f, 0.2f, 0.8f,
		0.5f, -0.5f, 0.0f, 	0.2f, 0.8f, 0.5f
	};

	GLuint sqrIndeces[] = {
		0, 1, 2,
		1, 2, 3
	};

	GLuint VAO2;
	glGenVertexArrays(1, &VAO2);
	GLuint VBO2;
	glGenBuffers(1, &VBO2); 
	GLuint EBO2;
	glGenBuffers(1, &EBO2);

	glBindVertexArray(VAO2);

		glBindBuffer(GL_ARRAY_BUFFER, VBO2);
		glBufferData(GL_ARRAY_BUFFER, sizeof(sqrVert), sqrVert, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(sqrIndeces), sqrIndeces, GL_STATIC_DRAW);
		
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);


	glBindVertexArray(0);
#endif
	// -- End of the square graphics --
	prog.useProgram();

	glm::mat4 projectionMat; // Projection / Screen Matrix
	glm::mat4 viewMat; // View / Camera Matrix
	glm::mat4 modelMat; // Model / Object Matrix

	modelMat = glm::scale(modelMat, glm::vec3(2.0f, 2.0f, 0.0f));
	modelMat = glm::translate(modelMat, glm::vec3(0.0f, 0.0f, 2.0f));
	viewMat = glm::translate(viewMat, glm::vec3(0.0f, 0.0f, -3.0f));
 	projectionMat= glm::perspective(glm::radians(60.0f), (GLfloat)WIDTH / (GLfloat)HEIGHT, 1.0f, 100.0f);

	GLuint projectionLocation = glGetUniformLocation(prog.f_program, "Projection");
	GLuint viewLocation = glGetUniformLocation(prog.f_program, "View");
	GLuint modelLocation = glGetUniformLocation(prog.f_program, "Model");

	glUniformMatrix4fv(projectionLocation, 1, GL_FALSE, glm::value_ptr(projectionMat));

	while(!window.close()){
		window.clear();

		glClearColor(1.0f, 0.5f, 0.2f, 1.0f);

		if(window.isKeyPressed(GLFW_KEY_ESCAPE))
			glfwSetWindowShouldClose(window.getWindowPointer(), true);

		modelMat = glm::rotate(modelMat, glm::radians(0.2f), glm::vec3(0.0f, 0.0f, 0.1f));

		//glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0, 3);
		//glBindVertexArray(0);

#if 1
		glBindVertexArray(VAO2);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
#endif

		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelMat)); // Model to the Shader.
		glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(viewMat)); // View to the Shader.

		window.update();
	}

	//glDeleteVertexArrays(1, &VAO);
	//glDeleteBuffers(1, &VBO);
	
#if 1
	glDeleteVertexArrays(1, &VAO2);
	glDeleteBuffers(1, &VBO2);
#endif

}
