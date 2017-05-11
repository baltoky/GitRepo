#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

namespace fission{
	enum CoordinateType{
		Vertex3DType,
		ColorType,
		TextureUVType
	};

	struct Coordinates{
		CoordinateType f_type;
		CoordinateType getType();
	};
	struct Vertex3D : public Coordinates{
		glm::vec3 f_vertex;
		Vertex3D();
		Vertex3D(glm::vec3 vertex);
		Vertex3D(float x, float y, float z);
	};

	struct Color : public Coordinates{
		glm::vec3 f_color;
		Color();
		Color(glm::vec3 color);
		Color(float r, float g, float b);
	};

	struct TextureUV : public Coordinates{
		glm::vec2 f_uv;
		TextureUV();
		TextureUV(glm::vec2 uv);
		TextureUV(float u, float v);
	};

	struct GraphicsData {
		GLfloat* f_data;
		std::vector<Vertex3D> f_coorVertex3D;
		std::vector<Color> f_coorColor;
		std::vector<TextureUV> f_coorTextureUV;
		void addVertex3D(Vertex3D vertex);
		void addColor(Color color);
		void addTextureUV(TextureUV texture);
		int getSize();
		void generateData();
	};
}
