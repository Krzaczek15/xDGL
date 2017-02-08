#pragma once

#include <string>
#include <iostream>

#include <glew.h>
#include <glm.hpp>
#include <gtc/type_ptr.hpp>

class Shader {
public:
	GLuint ID;

	Shader() {}
	Shader &Use();
	void Compile(const GLchar *vertexSource, const GLchar *fragmentSource, const GLchar *geometrySource = nullptr);
	void SetMatrix4(const GLchar* name, const glm::mat4 &matrix, GLboolean useShader = false);
private:
	void checkCompilerErrors(GLuint object, std::string type);
};

