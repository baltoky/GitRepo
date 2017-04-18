#include "shader.h"

namespace fission{

	/* Shader Class */

	Shader::Shader(char* shaderLocation, ShaderType type){
		f_type = type;
		size = 0;
		this->readShader(shaderLocation);
		this->compileShader();
	}

	void Shader::readShader(char* shaderLocation){
		std::ifstream iFile(shaderLocation);

		if(iFile.is_open()){

			// Get the size of the file, via going to the end of the file
			// and telling the count, then going back to the begining.
			iFile.seekg(0, iFile.end);
			size = iFile.tellg();
			iFile.seekg(0, iFile.beg);

			// Setting the Shader's file size. To make space for the last character we add 1 to size.
			f_shaderSource = new char[size + 1];

			// Empting the source array, to minimize bugs.
			for(int i = 0; i < size; i++){
					f_shaderSource[i] = ' ';
			}

			// Writing into the source.
			for(int i = 0; i < size; i++){
				iFile.get(f_shaderSource[i]);
			}

			// This is where we add that last character to end the sequence.
			f_shaderSource[size] = '\0';

		}
		else{
			std::cout << "ERROR: No path with that name." << std::endl;
		}

		iFile.close();
	}

	void Shader::compileShader(){

		switch(f_type){
			case vertexShader:
				f_shaderId = glCreateShader(GL_VERTEX_SHADER);
				break;
			case fragmentShader:
				f_shaderId = glCreateShader(GL_FRAGMENT_SHADER);
				break;
			default:
				std::cout << "SHADER ERROR: No shader type was found." << std::endl;
				break;
		}

		// glShaderSource : 
		// ( id of the shader we are compiling |
		// number of shaders |
		// the source code of the shader |
		// limit of the shader array )
		glShaderSource(f_shaderId, 1, &f_shaderSource, NULL);
		glCompileShader(f_shaderId);

		if(this->checkShaderError()){
			std::cout << "ERROR: shader " << f_type << " did not compile properly. " << std::endl;
		}

	}

	bool Shader::checkShaderError(){
		const int SIZE = 300;
		GLint success;
		GLchar infoLog[SIZE];

		glGetShaderiv(f_shaderId, GL_COMPILE_STATUS, &success);

		if(!success){
			glGetShaderInfoLog(f_shaderId, SIZE, NULL, infoLog);
			std::cout << "ERROR: Compilation failed in - " << f_type << infoLog << std::endl;
			return true;
		}
		else{
			return false;
		}
	}

	GLuint Shader::getShaderId(){
		return this->f_shaderId;
	}

	void Shader::deleteShader(){
		glDeleteShader(f_shaderId);
	}

	/* ShaderProgram Class */

	ShaderProgram::ShaderProgram(){
		// Use add to add shaders and createProgram to use the program.
		f_program = 0;
	}

	void ShaderProgram::useProgram(){
		glUseProgram(f_program);
	}

	void ShaderProgram::addShader(Shader& shader){
		f_shaders.push_back(shader);
	}

	void ShaderProgram::createProgram(){
		f_program = glCreateProgram();

		for(int i = 0; i < (signed)f_shaders.size(); i++){
			glAttachShader(f_program, f_shaders[i].getShaderId());
		}

		glLinkProgram(f_program);

		// Error checking...

		if(checkShaderProgramError())
			std::cout << "There was an error creating the program" << std::endl;
		
		for(int i = 0; i < (signed)f_shaders.size(); i++){
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
			std::cout << "ERROR: Shader failed to link. " << infoLog << std::endl;
			return true;
		}else{
			return false;
		}
	}

	GLuint ShaderProgram::getShaderProgram(){
		return f_program;
	}

}
