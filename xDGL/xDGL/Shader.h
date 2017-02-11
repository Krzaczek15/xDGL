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
	void setMatrix4(const GLchar* name, const glm::mat4 &matrix, GLboolean useShader = false);
	void setVector3(const GLchar* name, const glm::vec3 &vector, GLboolean useShader = false);
	void setFloat(const GLchar* name, const float &magicFloat, GLboolean useShader = false);
	void setInteger(const GLchar* name, GLint value, GLboolean useShader = false);
private:
	void checkCompilerErrors(GLuint object, std::string type);
};

