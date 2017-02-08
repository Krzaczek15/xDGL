#pragma once

#include "Object.h"

class Triangle : Object {
public:
	Triangle();
	virtual void Init() override;
	virtual void Draw(Shader shader, Camera* camera);
};

