#include "Sprite.h"

namespace fission{
	Sprite(){
		Sprite(0, 0, 1, 1);
	}
	Sprite(int x, int y, int width, int height){
		f_x = x;
		f_y = y;
		f_width = width;
		f_height = height;
		init();
	}
	Sprite(int x, int y, int width, int height, Color color){

	}
	Sprite(int x, int y, int width, int height, Color color, const char* filepath){

	}
	Sprite(glm::vec4 size){

	}
	~Sprite(){

	}
	void init(){

	}
	void render(){

	}
}
