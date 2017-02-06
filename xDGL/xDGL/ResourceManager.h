#pragma once
// Klasa od ³adowania tekstur, shaderów i zwalniania ich z pamiêci.

#include <glew.h>

#include <string>
#include <map>

#include "Shader.h"

class ResourceManager {
public:

	static std::map<std::string, Shader> Shaders;

	static Shader LoadShader(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile, std::string name);
	static Shader GetShader(std::string name);
	static void Clear();
private:
	ResourceManager() {}
	static Shader loadShaderFromFile(const GLchar *vShaderFile, const GLchar *fShaderFile, const GLchar *gShaderFile = nullptr);

};

