#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 col;

uniform float Scale;
uniform mat4 Projection;
//uniform mat4 move;

void main(){
	gl_Position = Projection * vec4(position.x * Scale, position.y * Scale, position.z * Scale, 1.0f);
	col = color;
}

