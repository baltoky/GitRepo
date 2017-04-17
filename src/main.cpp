#include "graphics/Window.h"
#include "graphics/shader/shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const int WIDTH = 1280;
const int HEIGHT = 720;

int main(int argc, char **argv)
{
	char* title = (char*)"The Little RPG";
	fission::Window window(WIDTH, HEIGHT, title, false);

	fission::ShaderProgram prog;
	fission::Shader vertex((char*)"src/graphics/shader/defaultVert.glsl", fission::vertexShader);
	fission::Shader fragment((char*)"src/graphics/shader/defaultFrag.glsl", fission::fragmentShader);
	prog.addShader(vertex);
	prog.addShader(fragment);
	prog.createProgram();

	// -- Starts organizing the triangle graphics -- 
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

	// -- Start of the square graphics -- 
	GLfloat sqrVert[] = {
		// Vertices, 		
		0.3f, 0.6f, 0.0f, 	0.8f, 0.5f, 0.2f,
		0.3f, 0.3f, 0.0f,	0.5f, 0.2f, 0.8f,
		0.6f, 0.6f, 0.0f,	0.5f, 0.2f, 0.8f,
		0.6f, 0.3f, 0.0f, 	0.2f, 0.8f, 0.5f
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

	// -- End of the square graphics --

	glm::mat4 projection;

	projection = glm::ortho(0.0f, (float)WIDTH, (float)HEIGHT, 0.0f, 0.1f, 100.0f);
	GLint projLoc = glGetUniformLocation(prog.getShaderProgram(), "projection");

	prog.useProgram();

	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

	while(!window.close()){
		window.clear();

		glClearColor(1.0f, 0.5f, 0.2f, 1.0f);

		if(window.isKeyPressed(GLFW_KEY_ESCAPE))
			glfwSetWindowShouldClose(window.getWindowPointer(), true);


		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		glBindVertexArray(VAO2);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		window.update();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteVertexArrays(1, &VAO2);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &VBO2);

}
