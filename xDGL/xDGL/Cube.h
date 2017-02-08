#pragma once

#include "Object.h"
#include "Camera.h"

class Cube : Object {
public:


	Cube();

	void Init() override;
	void Draw(Shader shader, Camera* camera) override;
};

