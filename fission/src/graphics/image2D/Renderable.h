#pragma once
#include <glm/glm.hpp>
#include "Texture.h"
#include "GraphicsData.h"

namespace fission{
	class Renderable{
		private:
			GLuint f_vbo;
			GLuint f_ebo;
			glm::vec2 f_center;
			glm::vec4 f_textureUV;
			short int f_textureID;
			float f_width;
			float f_height;
			float f_depth;
		public:
			Renderable(glm::vec2 center, float width, float height, float depth);
			~Renderable();
			void init();
			void setTextureUV(glm::vec4 textureUV);
			void setTextureID(short int id);
			short int getTextureID();
			void bind();
			void unbind();
	};
}
