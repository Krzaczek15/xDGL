#include "Camera.h"
Camera::Camera(glm::vec3 position, glm::vec3 up, GLfloat yaw, GLfloat pitch)
	   :cameraFront(glm::vec3(0.0f, 0.0f, -1.0f)), movementSpeed(SPEED), mouseSensitivity(SENSITIVTY) {
	cameraPos = position;
	worldUp = up;
	this->yaw = yaw;
	this->pitch = pitch;
	updateCameraVectors();
}

void Camera::processKeyboard(cameraMovement direction, GLfloat deltaTime) {
	GLfloat velocity = movementSpeed * deltaTime;
	
	switch (direction) {
	case FORWARD:
		cameraPos += cameraFront * velocity;
		//std::cout << movementSpeed << " " << cameraPos.x << " " << cameraPos.y << " " << cameraPos.z;
		break;
	case BACKWARD:
		cameraPos -= cameraFront * velocity;
		break;
	case LEFT:
		cameraPos -= cameraRight * velocity;
		break;
	case RIGHT:
		cameraPos += cameraRight * velocity;
		break;
	}
}

glm::mat4 Camera::getView() {
	return glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

void Camera::updateCameraVectors() {
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	cameraFront = glm::normalize(front);
	cameraRight = glm::normalize(glm::cross(cameraFront, worldUp));
	cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));
}

