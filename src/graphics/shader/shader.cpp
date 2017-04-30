#include <cstdlib>
#include "shader.h"

namespace fission{

	Shader::Shader(){}

	Shader::Shader(char* shaderFilePath, ShaderType type){
		f_shaderId = 0;
		f_type = type;
		readShader(shaderFilePath);
		compileShader();
	}

	void Shader::init(char* shaderFilePath, ShaderType type){
		f_shaderId = 0;
		f_type = type;
		readShader(shaderFilePath);
		compileShader();
	}

	void Shader::readShader(char* shaderLocation){
		int size = 0, i = 0;
		char temp;
		FILE *fp = fopen(shaderLocation, "r");

		if(fp == NULL){
			std::cout << "The file " << shaderLocation << " could not open." << std::endl;
			exit(1);
		}
		while(fscanf(fp, "%c", &temp) != EOF)size++;
		fclose(fp);

		f_shaderSource = new char[size];
		for(int j = 0; j < size; j++)
			f_shaderSource[j] = ' ';
		f_shaderSource[size - 1] = '\0';

		std::cout << f_shaderSource << std::endl;

		fp = fopen(shaderLocation, "r");
		while(fscanf(fp, "%c", &f_shaderSource[i]) != EOF){i++;}
		fclose(fp);
		f_shaderSource[size - 1] = '\0';

		std::cout << f_shaderSource << std::endl;

	}

	void Shader::compileShader(){
		switch(f_type){
			case vertexShader:
				f_shaderId = glCreateShader(GL_VERTEX_SHADER);
				break;
			case fragmentShader:
				f_shaderId = glCreateShader(GL_FRAGMENT_SHADER);
				break;
			case geometryShader: // TODO: add a geometry shader at some point.
				break;
			default:
				std::cout << "SHADER ERROR: Could not recognize shader type" << std::endl;
				break;
		}

		glShaderSource(f_shaderId, 1, &f_shaderSource, NULL);
		glCompileShader(f_shaderId);

		if(!checkShaderError()){
			std::cout << "There was no error douring the compilation of shader: " << this->f_shaderId <<
				" of type: " << f_type << std::endl;
		}
	}

	bool Shader::checkShaderError(){
		const int SIZE = 300;
		GLint success;
		GLchar infoLog[SIZE];

		glGetShaderiv(f_shaderId, GL_COMPILE_STATUS, &success);

		if(!success){
			glGetShaderInfoLog(f_shaderId, SIZE, NULL, infoLog);
			std::cout << "SHADER ERROR: There was an error compiling shader: " << f_shaderId <<
				", of type: " << f_type << std::endl;
			return true;
		}else
			return false;
	}

	void Shader::deleteShader(){
		glDeleteShader(f_shaderId);
	}

	GLuint Shader::getShaderId(){return this->f_shaderId;}
	ShaderType Shader::getShaderType(){return this->f_type;}

}
