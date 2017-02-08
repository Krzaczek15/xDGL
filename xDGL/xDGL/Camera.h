#pragma once

#include <glew.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

#include <vector>
#include <iostream>

enum cameraMovement {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

const GLfloat YAW = -90.0f;
const GLfloat PITCH = 0.0f;
const GLfloat SPEED = 3.0f;
const GLfloat SENSITIVTY = 0.25F;

class Camera {
public:
	// Kamera
	glm::vec3 cameraPos;
	glm::vec3 cameraFront;
	glm::vec3 cameraUp;
	glm::vec3 cameraRight;
	glm::vec3 worldUp;
	// K¹ty Eulera
	GLfloat yaw;
	GLfloat pitch;
	// Opcje
	GLfloat movementSpeed;
	GLfloat mouseSensitivity;

	Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), GLfloat yaw = YAW, GLfloat pitch = PITCH);
	glm::mat4 getView();
	void processKeyboard(cameraMovement direction, GLfloat deltaTime);

private:
	void updateCameraVectors();
};

