#version 330 core

layout (location = 0) in vec3 testPosition;
layout (location = 1) in vec3 testColor;

out vec3 Color;

void main() {
	gl_Position = vec4(testPosition, 1.0);
	Color = testColor;
}