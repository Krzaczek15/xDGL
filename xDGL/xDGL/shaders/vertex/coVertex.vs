#version 330 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec3 tColor;

out vec3 Color;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main() {
	gl_Position = projection * view * model * vec4(Position, 1.0);
	Color = tColor;
}