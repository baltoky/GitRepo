#include "graphics/Window.h"
#include "graphics/shader/shader.h"

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

	vertex.printShader();
	fragment.printShader();

	GLfloat vert[] = {
		// Vetices.			// Colors.
		-0.5f, -0.5f, 0.0f,		0.294f, 0.745f, 0.808f,
		0.5f, -0.5f, 0.0f,		1.0f, 0.071f, 0.431f,
		0.0f, 0.5f, 0.0f,		0.482f, 0.929f, 0.0f
	};

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	prog.useProgram();

	while(!window.close()){
		window.clear();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


		if(window.isKeyPressed(GLFW_KEY_ESCAPE))
			glfwSetWindowShouldClose(window.getWindowPointer(), true);


		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);

		window.update();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);

}
