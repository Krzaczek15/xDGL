#pragma once

#include "Shader.h"
#include "Camera.h"

#include <glew.h>
#include <glm.hpp>
#include <vector>

#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include <glfw3.h>

class Object {
public:
	GLuint VAO, VBO, EBO;

	struct colorVertex {
		glm::vec3 position;
		glm::vec3 color;
	};

	struct textureVertex : colorVertex {
		glm::vec3 texPos;
	};

	//Póki nie napisa³em oœwietlenia, to nie ma co siê w to bawiæ.
	/*struct lightingVertex : textureVertex {
		glm::vec3 LightPos;
	};*/	

	std::vector<colorVertex> colorVertices;
	std::vector<textureVertex> textureVertices;

	std::vector<GLuint> indices;

	virtual void Init() = 0;

	virtual void Draw(Shader shader, Camera* camera) = 0;

	//virtual void Translate() = 0;
	//virtual void rotateX() = 0;
	//virtual void rotateY() = 0;
	//virtual void rotateZ() = 0;
};

