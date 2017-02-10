#pragma once

#include <glew.h>

class Texture2D
{
public:
	GLuint ID;

	GLuint width, height;

	GLuint internalFormat;
	GLuint imageFormat;

	GLuint wrapS;
	GLuint wrapT;
	GLuint filterMin;
	GLuint filterMax;

	Texture2D();

	void Generate(GLuint width, GLuint height, unsigned char* data);

	void Bind() const;
};

