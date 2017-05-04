#include "graphics/Window.h"
#include "graphics/shader/shader.h"
#include "graphics/texture/Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
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

	// Texture Loading.
	
#if 0
	int textWidth, textHeight, bitsPerPixel;
	unsigned char* image = stbi_load("./img/Dickbut.png", &textWidth, &textHeight, &bitsPerPixel, 3);
	if(image == NULL){
		std::cout << "Image loading failed..." << std::endl;
		return 1;
	}

	GLuint f_Texture;
	glGenTextures(1, &f_Texture);
#endif

#if 1
	// -- Start of the square graphics -- 
	GLfloat sqrVert[] = {
		// Vertices, 		Colors			Textures
		-0.5f, 0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f
	};

	GLfloat colVert[] = {
		0.0f, 0.5f, 0.2f,
		0.5f, 0.2f, 0.8f,
		0.5f, 0.2f, 0.8f,
		0.2f, 0.8f, 0.5f
	};

	GLfloat texVert[] = {
		1.0f, 0.0f,
		0.0f, 0.0f,
		1.0f, 1.0f,
		0.0f, 1.0f
	};

	GLuint sqrIndeces[] = {
		0, 1, 2,
		1, 2, 3
	};

	GLuint VAO2;
	glGenVertexArrays(1, &VAO2);
	GLuint vertexVBO2;
	glGenBuffers(1, &vertexVBO2); 
	GLuint colorVBO2;
	glGenBuffers(1, &colorVBO2);
	GLuint textureVBO2;
	glGenBuffers(1, &textureVBO2);
	GLuint EBO2;
	glGenBuffers(1, &EBO2);

	glBindVertexArray(VAO2);

		glBindBuffer(GL_ARRAY_BUFFER, vertexVBO2);
		glBufferData(GL_ARRAY_BUFFER, sizeof(sqrVert), sqrVert, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, colorVBO2);
		glBufferData(GL_ARRAY_BUFFER, sizeof(colVert), colVert, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, textureVBO2);
		glBufferData(GL_ARRAY_BUFFER, sizeof(texVert), texVert, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO2);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(sqrIndeces), sqrIndeces, GL_STATIC_DRAW);

		fission::Texture2D texture;
		if(!texture.readTexture("./img/Dickbut.png")){
			std::cout << "Error reading the image." << std::endl;
		}

		glBindBuffer(GL_ARRAY_BUFFER, vertexVBO2);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, colorVBO2);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, textureVBO2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(2);
		glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0);
#endif
	//stbi_image_free(image);
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
		//glBindTexture(GL_TEXTURE_2D, f_Texture);
		texture.bind();
		glBindVertexArray(VAO2);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
#endif

		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(modelMat)); // Model to the Shader.
		glUniformMatrix4fv(viewLocation, 1, GL_FALSE, glm::value_ptr(viewMat)); // View to the Shader.

		window.update();
	}

	//glDeleteVertexArrays(1, &VAO);
	//glDeleteBuffers(1, &VBO);
	
#if 1
	glDeleteVertexArrays(1, &VAO2);
	glDeleteBuffers(1, &vertexVBO2);
	glDeleteBuffers(1, &colorVBO2);
	glDeleteBuffers(1, &textureVBO2);
#endif

}
