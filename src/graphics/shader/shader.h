#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <GL/glew.h>

namespace fission{

	enum ShaderType{
		vertexShader = 1,
		fragmentShader = 2
	};

	class Shader{
		private:
			GLuint f_shaderId;
			char* f_shaderSource;
			ShaderType f_type;
			int size;
		public:
			Shader(char* shaderLocation, ShaderType type);
			void readShader(char* shaderLocation);
			void compileShader();
			bool checkShaderError();
			void deleteShader();
			GLuint getShaderId();
	};

	class ShaderProgram{
		private:
			GLuint f_program;
			std::vector<Shader> f_shaders;
		public:
			ShaderProgram();
			void useProgram();
			void addShader(Shader& shader);
			void createProgram();
			bool checkShaderProgramError();
			GLuint getProgram();
			
	};

}
