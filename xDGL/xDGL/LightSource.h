#pragma once

#include "Object.h"
#include "Camera.h"

class LightSource : Object {
public:
	LightSource();

	void Init() override;
	void Draw(Shader shader, Camera* camera) override;
};

