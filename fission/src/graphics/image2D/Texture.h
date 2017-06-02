#pragma once
#define STD_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <GL/glew.h>

namespace fission{
	struct Texture2D{
		GLuint f_textureId;
		int f_width;
		int f_height;
		char* f_filepath;
		Texture2D(const char* filepath);
		~Texture2D();
		bool readTexture();
		bool readTexture(const char* filepath);
		void bind();
		void unbind();
	};

}
