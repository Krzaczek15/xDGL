#pragma once

#include "Object.h"
#include "Camera.h"

class LightSource : Object {
public:
	glm::vec3 lightPos;

	LightSource();

	void Init() override;
	void Draw(Shader shader, Camera* camera);
	glm::vec3 getPosition();
};

