#include "GraphicsData.h"

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
		int size;
		size += f_coorVertex3D.size() * 3;
		size += f_coorColor.size() * 3;
		size += f_coorTextureUV.size() * 2;
		return size;
	}
	int GraphicsData::getSize(int &numVertex3D, int &numColor, int &numTextureUV){
		numVertex3D = f_coorVertex3D.size();
		numColor = f_coorColor.size();
		numTextureUV = f_coorTextureUV.size();
		return getSize();
	}
	void GraphicsData::generateData(){
		int size = getSize();
		int i = 0;
		f_data = new GLfloat[size];
		do{

		}while(i < size);
	}

}
