#include "Shader.h"



Shader &Shader::Use()
{
	glUseProgram(this->ID);
	return *this;
}

void Shader::Compile(const GLchar* vertexSource, const GLchar* fragmentSource, const GLchar* geometrySource) {
	GLuint sVertex, sFragment, gShader;

	sVertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(sVertex, 1, &vertexSource, NULL);
	glCompileShader(sVertex);
	checkCompilerErrors(sVertex, "VERTEX");

	sFragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(sFragment, 1, &fragmentSource, NULL);
	glCompileShader(sFragment);
	checkCompilerErrors(sFragment, "FRAGMENT");

	if (geometrySource != nullptr) {
		gShader = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(gShader, 1, &geometrySource, NULL);
		glCompileShader(gShader);
		checkCompilerErrors(gShader, "GEOMETRY");
	}

	this->ID = glCreateProgram();
	glAttachShader(this->ID, sVertex);
	glAttachShader(this->ID, sFragment);
	if (geometrySource != nullptr)
	{
		glAttachShader(this->ID, gShader);
	}
	glLinkProgram(this->ID);
	checkCompilerErrors(this->ID, "PROGRAM");

	glDeleteShader(sVertex);
	glDeleteShader(sFragment);

	if (geometrySource != nullptr) {
		glDeleteShader(gShader);
	}
}

void Shader::checkCompilerErrors(GLuint object, std::string type) 
{
	GLint success;
	GLchar infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(object, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(object, 1024, NULL, infoLog);
			std::cout << "Failed to compile " << type << " shader!" << "\n"
				<< infoLog << std::endl;
		}
		else
		{
			glGetProgramiv(object, GL_LINK_STATUS, &success);

			if (!success) {
				glGetProgramInfoLog(object, 1024, NULL, infoLog);
				std::cout << "Failed to compile " << type << "!" << "\n"
					<< infoLog << std::endl;
			}
		}
	}
}