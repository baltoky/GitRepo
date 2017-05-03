#version 330 core

in vec3 col;
in vec2 tex;

out vec4 color;

uniform sampler2D texSampler;

void main(){
	color = vec4(col, 1.0f) * texture(texSampler, tex);
}

