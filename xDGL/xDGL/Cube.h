#pragma once

#include "Object.h"
#include "Camera.h"

class Cube : Object {
public:
	Cube();

	glm::vec3 cubePos;
	glm::vec3 cubeColor;

	void Init() override;
	void Draw(Shader shader, Camera* camera, glm::vec3 lightPos);

	void setPosition(glm::vec3 position);
	void setColor(glm::vec3 color);
};

