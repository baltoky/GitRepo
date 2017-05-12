#version 330 core

in vec3 col;
in vec2 tex;

out vec4 color;

uniform sampler2D texSampler;

void main(){
	//color =  mix(vec4(col, 1.0f) , texture(texSampler, tex), 0.2f);
	color = texture(texSampler, tex);
}

