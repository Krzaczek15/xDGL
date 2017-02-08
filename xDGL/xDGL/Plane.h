#pragma once

#include "Object.h"
class Plane : Object {
public:
	Plane();

	void Init() override;

	void Draw(Shader shader, Camera* camera) override;

};

