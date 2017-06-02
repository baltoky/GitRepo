#include "Texture.h"
#include <iostream>

namespace fission{

	Texture2D::Texture2D(const char* filepath){
		f_filepath = (char*)filepath;
	}

	Texture2D::~Texture2D(){
		glDeleteBuffers(1, &f_textureId);
	}

	bool Texture2D::readTexture(const char* filepath){
		int bpp;
		unsigned char* data = stbi_load(filepath, &f_width, &f_height, &bpp, 0);
		if(data == NULL)
			return false;
		glGenTextures(1, &f_textureId);
		glBindTexture(GL_TEXTURE_2D, f_textureId);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		if(bpp == 3){
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, f_width, f_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		}
		if(bpp == 4){
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, f_width, f_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		}
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, 0);
		stbi_image_free(data);
		bpp = 0;
		return true;
	}

	bool Texture2D::readTexture(){
		return readTexture((const char*)f_filepath);
	}

	void Texture2D::bind(){
		glBindTexture(GL_TEXTURE_2D, f_textureId);
	}

	void Texture2D::unbind(){
		glBindTexture(GL_TEXTURE_2D, 0);
	}

}
