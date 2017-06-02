#pragma once

#include "Renderable.h"
#include "Texture.h"
#include <vector>
#include <iostream>

namespace fission{
	class Batch{
		private:
			std::vector<Renderable> f_allRenderables;
			std::vector<Texture2D> f_allTextures;
			std::vector<GLuint> f_allVAO;
		public:
			void addRenderable(Renderable &renderable,
					int textureID);
			void addTexture(const char* filepath);
			void createBatch(int textureID);
			void sortByTextureID();
			void sortByDepth();
			void renderBatch(int batchIndex);
	};
}
