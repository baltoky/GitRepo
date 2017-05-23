#pragma once

#include "Texture.h"
#include "GraphicsData.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace fission{
	class Sprite{
		private:
			GLuint f_vbo;
			GLuint f_ebo;
			glm::vec4 f_vertexDimenssion;
			glm::vec4 f_textureDimenssion;
			const char* f_filepath;
			Texture2D f_texture;
			glm::mat4 f_modelMatrix;
			GLuint f_modelLocation;
		public:
			Sprite();
			Sprite(int x, int y, int width, int height);
			Sprite(int x, int y, int width, int height, const char* filepath);
			Sprite(glm::vec4 size);
			Sprite(glm::vec4 size, const char* filepath);
			~Sprite();
			void setTextureDimenssion(glm::vec4 dimenssion);
			void setTextureDimenssion(float u, float v, float width, float height);
			void init();
			void draw();
			void setTexture(const char* filepath);
			void getModelLocation(GLuint shaderID, const char* shaderVariable);
			void useModelMatrix();
	};
}
