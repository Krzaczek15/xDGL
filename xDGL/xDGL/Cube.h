#pragma once

#include "Object.h"

class Cube : Object{
public:
	Cube();

	void Init() override;
	void Draw(Shader shader) override;
};

