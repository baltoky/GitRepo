#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 col;

// When utilizing these, use in reverse order. Model, View, Projection.
uniform mat4 Projection;
uniform mat4 View;
uniform mat4 Model;

void main(){
	gl_Position =  Projection * View *  Model * vec4(position.x , position.y , position.z , 1.0f);
	col = color;
}

