#include "BatchRender.h"

namespace fission{

	void Batch::addRenderable(Renderable& renderable, int textureID){
		renderable.setTextureID((short)textureID);
		f_allRenderables.push_back(renderable);
	}
	void Batch::addTexture(const char* filepath){
		f_allTextures.push_back(Texture2D(filepath));
	}

	void Batch::createBatch(int textureID){
		GLuint vao = 0;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		if(!f_allTextures[textureID].readTexture()){
			std::cout << "ERROR: reading texture " << textureID << std::endl;
		}
		for(int i = 0; i < f_allRenderables.size(); i++){
			if(f_allRenderables[i].getTextureID() == textureID){
				f_allRenderables[i].init();
			}
		}
		glBindVertexArray(0);
		f_allVAO.push_back(vao);
	}

	void Batch::renderBatch(int batchIndex){
		glBindVertexArray(f_allVAO[batchIndex]);
		f_allTextures[batchIndex].bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		f_allTextures[batchIndex].unbind();
		glBindVertexArray(0);
	}

}
