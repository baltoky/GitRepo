#pragma once

#include "BufferObjects.h"
#include "Texture.h"

namespace fission{
	class Sprite{
		private:
			int f_width;
			int f_height;
			int f_x;
			int f_y;
			Vertex f_vertex;
			Color f_color;
			Texture f_texture;
			TextureUV f_textCoord;
			Element f_element;
		public:
			Sprite();
			Sprite(int x, int y, int width, int height);
			Sprite(int x, int y, int width, int height, Color color);
			Sprite(int x, int y, int width, int height, Color color, const char* filepath);
			Sprite(glm::vec4 size);
			~Sprite();
			void init();
			void render();
			void setTexture(const char* filepath);
	};
}
