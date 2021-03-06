#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 texture;

out vec3 col;
out vec2 tex;

uniform mat4 Projection;
uniform mat4 View;
uniform mat4 Model;

void main(){
	gl_Position =  Projection * View *  Model * vec4(position.x , position.y , position.z , 1.0f);
	col = color;
	tex = texture;
}

