#include "graphics/Window.h"
#include "shader/shader.h"

const int WIDTH = 1280;
const int HEIGHT = 720;

int main(int argc, char **argv)
{
	char* title = (char*)"The Little RPG";
	fission::Window window(WIDTH, HEIGHT, title, false);

	fission::ShaderProgram prog;
	fission::Shader vertex((char*)"src/shader/defaultVert.glsl", fission::vertexShader);
	fission::Shader fragment((char*)"src/shader/defaultFrag.glsl", fission::fragmentShader);
	prog.addShader(vertex);
	prog.addShader(fragment);
	prog.createProgram();

	GLfloat vert[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	while(!window.close()){
		window.clear();

		glClearColor(0.667f, 0.224f, 0.224f, 1.0f);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		if(window.isKeyPressed(GLFW_KEY_ESCAPE))
			glfwSetWindowShouldClose(window.getWindowPointer(), true);

		window.update();
	}

	glDeleteBuffers(1, &VBO);

}
