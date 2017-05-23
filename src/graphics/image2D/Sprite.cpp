#include "Sprite.h"

namespace fission{
	Sprite::Sprite(){
		Sprite(0, 0, 1, 1);
	}
	Sprite::Sprite(int x, int y, int width, int height){
		f_vbo = 0;
		f_vertexDimenssion = glm::vec4((float)x, (float)y, (float)width, (float)height);
		setTextureDimenssion(0, 0, 1, 1);
	}
	Sprite::Sprite(int x, int y, int width, int height, const char* filepath){
		Sprite(x, y, width, height);
		f_filepath = filepath;
	}
	Sprite::Sprite(glm::vec4 size){
		Sprite(size.x, size.y, size.z, size.w);
	}
	Sprite::Sprite(glm::vec4 size, const char* filepath){
		Sprite(size.x, size.y, size.z, size.w, filepath);
	}
	Sprite::~Sprite(){
		glDeleteBuffers(1, &f_vbo);
		glDeleteBuffers(1, &f_ebo);
	}
	void Sprite::setTextureDimenssion(glm::vec4 dimenssion){
		f_textureDimenssion = dimenssion;
	}
	void Sprite::setTextureDimenssion(float u, float v, float width, float height){
		f_textureDimenssion = glm::vec4(u, v, width, height);
	}
	void Sprite::init(){
		GLuint elem[] = {
			0, 1, 2,
			1, 2, 3
		};
		GraphicsData data;
		// Vertex Coordinates.
		data.addVertex3D(Vertex3D(f_vertexDimenssion.x, f_vertexDimenssion.y, 0.0f));
		data.addVertex3D(Vertex3D(f_vertexDimenssion.x, f_vertexDimenssion.y + f_vertexDimenssion.w, 0.0f));
		data.addVertex3D(Vertex3D(f_vertexDimenssion.x + f_vertexDimenssion.z, f_vertexDimenssion.y + f_vertexDimenssion.w, 0.0f));
		data.addVertex3D(Vertex3D(f_vertexDimenssion.x + f_vertexDimenssion.z, f_vertexDimenssion.y, 0.0f));
		// Texture Coordinates.
		data.addTextureUV(TextureUV(f_textureDimenssion.x, f_textureDimenssion.y));
		data.addTextureUV(TextureUV(f_textureDimenssion.x, f_textureDimenssion.y + f_textureDimenssion.w));
		data.addTextureUV(TextureUV(f_textureDimenssion.x + f_textureDimenssion.z, f_textureDimenssion.y));
		data.addTextureUV(TextureUV(f_textureDimenssion.x + f_textureDimenssion.z, f_textureDimenssion.y + f_textureDimenssion.w));

		glGenBuffers(1, &f_vbo);
		glGenBuffers(1, &f_ebo);
		
		glBindBuffer(GL_ARRAY_BUFFER, f_vbo);
		glBufferData(GL_ARRAY_BUFFER, data.getSize(), data.f_data, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, f_ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elem), elem, GL_STATIC_DRAW);

		f_texture.readTexture(f_filepath);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	}
	void Sprite::draw(){
		glBindBuffer(GL_ARRAY_BUFFER, f_vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, f_ebo);
		f_texture.bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindBuffer(GL_TEXTURE_2D, 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
	void Sprite::getModelLocation(GLuint shaderID, const char* shaderVariable){
		f_modelLocation = glGetUniformLocation(shaderID, shaderVariable);
	}
	void Sprite::useModelMatrix(){
		glUniformMatrix4fv(f_modelLocation, 1, GL_FALSE, glm::value_ptr(f_modelMatrix));
	}
}
