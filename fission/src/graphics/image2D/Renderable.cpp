#include "Renderable.h"

namespace fission{

	Renderable::Renderable(glm::vec2 center, 
		float width, 
		float height,
		float depth){

		f_textureUV = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
		f_textureID = 0;
		f_center = center;
		f_width = width;
		f_height = height;
		f_depth = depth;

	}

	Renderable::~Renderable(){
		glDeleteBuffers(1, &f_vbo);
		glDeleteBuffers(1, &f_ebo);
	}

	void Renderable::init(){
		GraphicsData data;

		data.addVertex3D(Vertex3D(f_center.x - (f_width / 2.0f), f_center.y + (f_height / 2.0f), f_depth));
		data.addVertex3D(Vertex3D(f_center.x - (f_width / 2.0f), f_center.y - (f_height / 2.0f), f_depth));
		data.addVertex3D(Vertex3D(f_center.x + (f_width / 2.0f), f_center.y + (f_height / 2.0f), f_depth));
		data.addVertex3D(Vertex3D(f_center.x + (f_width / 2.0f), f_center.y - (f_height / 2.0f), f_depth));

		data.addColor(Color(1.0f, 1.0f, 1.0f));

		data.addTextureUV(TextureUV(f_textureUV.x + f_textureUV.z, f_textureUV.y));
		data.addTextureUV(TextureUV(f_textureUV.x, f_textureUV.y));
		data.addTextureUV(TextureUV(f_textureUV.x + f_textureUV.z, f_textureUV.y + f_textureUV.w));
		data.addTextureUV(TextureUV(f_textureUV.x, f_textureUV.y + f_textureUV.w));

		data.generateData();

		GLuint indeces[] = {
			0, 1, 2,
			1, 2, 3
		};
		
		glGenBuffers(1, &f_vbo);
		glGenBuffers(1, &f_ebo);

		bind();

		glBufferData(GL_ARRAY_BUFFER, data.getSize(), data.f_data, GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeces), indeces, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0); // The Vertex location on a Vertex shader.
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);

		glEnableVertexAttribArray(1); // The Color location on a Vertex shader.
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		
		glEnableVertexAttribArray(2); // The Texture coordinate location on a Vertex shader.
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));

	}

	void Renderable::setTextureUV(glm::vec4 textureUV){
		f_textureUV = textureUV;
	}

	void Renderable::setTextureID(short int id){
		f_textureID = id;
	}

	short int Renderable::getTextureID(){return this->f_textureID;}

	void Renderable::bind(){
		glBindBuffer(GL_ARRAY_BUFFER, f_vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, f_ebo);
	}

	void Renderable::unbind(){
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}
