#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <GL/glew.h>

namespace fission{

	enum ShaderType{
		vertexShader = 1,
		fragmentShader = 2,
		geometryShader = 3
	};

	class Shader{
		private:
			GLuint f_shaderId;
			ShaderType f_type;
			char* f_shaderSource;
		public:
			GLuint f_program;
			Shader();
			Shader(char* shaderFilePath, ShaderType type);
			void init(char* shaderFilePath, ShaderType type);
			void readShader(char* shaderLocation);
			void compileShader();
			void deleteShader();
			bool checkShaderError();
			GLuint getShaderId();
			ShaderType getShaderType();
	};

	class ShaderProgram{
		private:
			Shader* f_shaders;
			int f_shadersSize;
		public:
			GLuint f_program;
			ShaderProgram(char* vertex);
			ShaderProgram(char* vertex, char* fragment);
			ShaderProgram(char* vertex, char* fragment, char* geometry);
			void createProgram();
			bool checkShaderProgramError();
			void useProgram();
	};

}
