#pragma once

#include <string>
#include <iostream>

#include <glew.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>

class Shader
{
public:
	GLuint ID;

	Shader() {}
	Shader &Use();
	void Compile(const GLchar *vertexSource, const GLchar *fragmentSource, const GLchar *geometrySource = nullptr);

private:
	void checkCompilerErrors(GLuint object, std::string type);
};

