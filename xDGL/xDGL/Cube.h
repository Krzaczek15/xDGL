#pragma once

#include "Object.h"
#include "Camera.h"

class Cube : Object {
public:
	Cube();

	glm::vec3 cubePos;

	void Init() override;
	void Draw(Shader shader, Camera* camera, glm::vec3 lightPos);
};

