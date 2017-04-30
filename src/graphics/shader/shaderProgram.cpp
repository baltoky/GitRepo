#include "shader.h"

namespace fission{
	
	ShaderProgram::ShaderProgram(char* vertex){
		f_shaders = new Shader[1];
		f_shaders[0].init(vertex, vertexShader);
		f_program = 0;
		f_shadersSize = 1;

		createProgram();
	}

	ShaderProgram::ShaderProgram(char* vertex, char* fragment){
		f_shaders = new Shader[2];
		f_shaders[0].init(vertex, vertexShader);
		f_shaders[1].init(fragment, fragmentShader);
		f_program = 0;
		f_shadersSize = 2;

		createProgram();
	}

	ShaderProgram::ShaderProgram(char* vertex, char* fragment, char* geometry){
		f_shaders = new Shader[3];
		f_shaders[0].init(vertex, vertexShader);
		f_shaders[1].init(fragment, fragmentShader);
		f_shaders[2].init(geometry, geometryShader);
		f_program = 0;
		f_shadersSize = 3;

		createProgram();
	}

	void ShaderProgram::useProgram(){
		glUseProgram(f_program);
	}

	void ShaderProgram::createProgram(){
		f_program = glCreateProgram();

		for(int i = 0; i < f_shadersSize; i++){
			glAttachShader(f_program, f_shaders[i].getShaderId());
		}

		glLinkProgram(f_program);

		if(!checkShaderProgramError()){
			std::cout << "The Shader Program linked successfuly." << std::endl;
		}

		for(int i = 0; i < f_shadersSize; i++){
			f_shaders[i].deleteShader();
		}
	}

	bool ShaderProgram::checkShaderProgramError(){
		const int SIZE = 300;
		GLint success;
		GLchar infoLog[SIZE];

		glGetProgramiv(f_program, GL_COMPILE_STATUS, &success);

		if(!success){
			glGetProgramInfoLog(f_program, SIZE, NULL, infoLog);
			std::cout << "SHADER_PROGRAM ERROR: Could not link correctly.\n" << infoLog << std::endl;
			return true;
		}else
			return false;
	}

}
