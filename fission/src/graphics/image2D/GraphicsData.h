#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

namespace fission{
	enum CoordinateType{
		Vertex2DType,
		Vertex3DType,
		ColorType,
		TextureUVType
	};

	struct Coordinates{
		CoordinateType f_type;
		CoordinateType getType();
	};

	struct Vertex2D : public Coordinates{
		glm::vec2 f_vertex;
		Vertex2D();
		Vertex2D(glm::vec2 vertex);
		Vertex2D(float x, float y);
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
		signed short int f_column;
		signed short int f_row;
		std::vector<Vertex2D> f_coorVertex2D;
		std::vector<Vertex3D> f_coorVertex3D;
		std::vector<Color> f_coorColor;
		std::vector<TextureUV> f_coorTextureUV;
		~GraphicsData();
		void addVertex2D(Vertex2D vertex);
		void addVertex3D(Vertex3D vertex);
		void addColor(Color color);
		void addTextureUV(TextureUV texture);
		void setColumn(int col);
		void setRow(int row);
		int getArrayLength();
		int getSize();
		void generateData();
	};
}
