#include "GraphicsData.h"
#include <iostream>

namespace fission{

	CoordinateType Coordinates::getType(){return f_type;}

	Vertex3D::Vertex3D(){
		f_type = Vertex3DType;
		f_vertex = glm::vec3(0.0f, 0.0f, 0.0f);
	}
	Vertex3D::Vertex3D(glm::vec3 vertex){
		f_type = Vertex3DType;
		f_vertex = vertex;
	}
	Vertex3D::Vertex3D(float x, float y, float z){
		f_type = Vertex3DType;
		f_vertex = glm::vec3(x, y, z);
	}

	Color::Color(){
		f_type = ColorType;
		f_color = glm::vec3(0.0f, 0.0f, 0.0f);
	}
	Color::Color(glm::vec3 color){
		f_type =ColorType;
		f_color = color;
	}
	Color::Color(float r, float g, float b){
		f_type = ColorType;
		f_color = glm::vec3(r, g, b);
	}

	TextureUV::TextureUV(){
		f_type = TextureUVType;
		f_uv = glm::vec2(0.0f, 0.0f);
	}
	TextureUV::TextureUV(glm::vec2 uv){
		f_type = TextureUVType;
		f_uv = uv;
	}
	TextureUV::TextureUV(float u, float v){
		f_type = TextureUVType;
		f_uv = glm::vec2(u, v);
	}

	void GraphicsData::addVertex3D(Vertex3D vertex){
		f_coorVertex3D.push_back(vertex);
	}
	void GraphicsData::addColor(Color color){
		f_coorColor.push_back(color);
	}
	void GraphicsData::addTextureUV(TextureUV texture){
		f_coorTextureUV.push_back(texture);
	}
	int GraphicsData::getSize(){
		unsigned int row = 0;
		unsigned int column = 0;
		if(f_coorVertex3D.size() > 0){
			row = f_coorVertex3D.size();
			column += 3;
		}
		if(f_coorColor.size() > 0){
			if(row < f_coorColor.size())
				row = f_coorColor.size();
			column += 3;
		}
		if(f_coorTextureUV.size() > 0){
			if(row < f_coorTextureUV.size())
				row = f_coorTextureUV.size();
			column += 2;
		}
		int size = column * row;
		return size;
	}
	void GraphicsData::generateData(){
		int size = getSize();
		int i = 0;
		int a = 0, b = 0, c = 0;
		f_data = new GLfloat[size];
		for(int j = 0; j < size; j++){
			f_data[j] = 0.0f;
			std::cout << f_data[j] << std::endl;
		}
		do{
			if(f_coorVertex3D.size() > 0){
				f_data[i] = f_coorVertex3D[a].f_vertex.x;
				i++;
				f_data[i] = f_coorVertex3D[a].f_vertex.y;
				i++;
				f_data[i] = f_coorVertex3D[a].f_vertex.z;
				i++;
				if(a < f_coorVertex3D.size() - 1)
					a++;
			}
			if(f_coorColor.size() > 0){
				f_data[i] = f_coorColor[b].f_color.x;
				i++;
				f_data[i] = f_coorColor[b].f_color.y;
				i++;
				f_data[i] = f_coorColor[b].f_color.z;
				i++;
				if(b < f_coorColor.size() - 1)
					b++;
			}
			if(f_coorTextureUV.size() > 0){
				f_data[i] = f_coorTextureUV[c].f_uv.x;
				i++;
				f_data[i] = f_coorTextureUV[c].f_uv.x;
				i++;
				if(c < f_coorTextureUV.size() - 1)
					c++;
			}
		}while(i < size);
	}

}
