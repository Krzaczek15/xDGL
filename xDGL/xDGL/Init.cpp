#include "Window.h"
#include "ResourceManager.h"
#include "Shader.h"
#include "Texture2D.h"

#include "Camera.h"

#include "Triangle.h"
#include "Plane.h"
#include "Cube.h"
#include "LightSource.h"

#include <src/SOIL.h>

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouseCallback(GLFWwindow* window, double xpos, double ypos);
void doMovement();

bool keys[1024];

Window* window = new Window(keyCallback, mouseCallback);
Camera* camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));

GLfloat lastX = 400, lastY = 300;
bool firstMouse = true;


GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

int main() {
	Shader lampShader = ResourceManager::LoadShader("shaders/vertex/vs_lamp.glvs", "shaders/fragment/fs_lamp.glfs", nullptr, "vertex");
	Shader lightingShader = ResourceManager::LoadShader("shaders/vertex/vs_lighting.glvs", "shaders/fragment/fs_lighting.glfs", nullptr, "fragment");

	Texture2D diffuseTex = ResourceManager::LoadTexture("textures/container.png", GL_FALSE, "diffuse");
	Texture2D specularTex = ResourceManager::LoadTexture("textures/specular.png", GL_FALSE, "specular");

	std::vector<Cube> cubes(10);
	std::vector<LightSource> lights(4);

	std::vector<glm::vec3> cubesPositions = {
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	std::vector<glm::vec3> lightPositions = {
		glm::vec3(0.7f, 0.2f, 2.0f),
		glm::vec3(2.3f, -3.3f, -4.0f),
		glm::vec3(-4.0f, -2.0f, -15.0f),
		glm::vec3(0.0f, 0.0f, -3.0f)
	};

	std::vector<glm::vec3> lightColors = {
		glm::vec3(1.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f),
		glm::vec3(1.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f)
	};

	lightingShader.Use();
	lightingShader.setInteger("material.diffuse", 0);
	lightingShader.setInteger("material.specular", 1);

	while (!window->isClose()) {
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();
		doMovement();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		lightingShader.Use();

		lightingShader.setVector3("viewPos", camera->cameraPos);
		lightingShader.setFloat("material.shininess", 32.0f);

		lightingShader.setVector3("dirLight.direction", glm::vec3(-0.2f, -1.0f, -0.3f));
		lightingShader.setVector3("dirLight.ambient", glm::vec3(0.05f, 0.05f, 0.05f));
		lightingShader.setVector3("dirLight.diffuse", glm::vec3(0.4f, 0.4f, 0.4f));
		lightingShader.setVector3("dirLight.specular", glm::vec3(0.5f, 0.5f, 0.5f));

		for (GLuint i = 0; i < 4; i++)
		{
			std::string number = std::to_string(i);
			lightingShader.setVector3(("pointLights[" + number + "].position").c_str(), lightPositions.at(i));
			lightingShader.setVector3(("pointLights[" + number + "].ambient").c_str(), glm::vec3(0.01f, 0.01f, 0.01f));
			lightingShader.setVector3(("pointLights[" + number + "].diffuse").c_str(), lightColors.at(i));
			lightingShader.setVector3(("pointLights[" + number + "].specular").c_str(), glm::vec3(1.0f, 1.0f, 1.0f));
			lightingShader.setFloat(("pointLights[" + number + "].constant").c_str(), 1.0f);
			lightingShader.setFloat(("pointLights[" + number + "].linear").c_str(), 0.09f);
			lightingShader.setFloat(("pointLights[" + number + "].quadratic").c_str(), 0.032f);
		}

		glActiveTexture(GL_TEXTURE0);
		diffuseTex.Bind();
		glActiveTexture(GL_TEXTURE1);
		specularTex.Bind();

		for (int i = 0; i < cubes.size(); i++) {
			cubes.at(i).setPosition(cubesPositions.at(i));
			cubes.at(i).Draw(lightingShader, camera); 
		}

		lampShader.Use();

		for (GLuint i = 0; i < 4; i++)
		{
			lampShader.setVector3("lightColor", lightColors.at(i));
			lights.at(i).Draw(lampShader, camera);
			lights.at(i).setPosition(lightPositions.at(i));
		}

		glfwSwapBuffers(window->getWindow());
	}

	glfwTerminate();

	return 0; // Pamiêtajcie dzieciaczki. Nie macie kopi zapasowej - nie istniejecie.
}

void doMovement() {
	if (keys[GLFW_KEY_W])
		camera->processKeyboard(FORWARD, deltaTime);
	if (keys[GLFW_KEY_S])
		camera->processKeyboard(BACKWARD, deltaTime);
	if (keys[GLFW_KEY_A])
		camera->processKeyboard(LEFT, deltaTime);
	if (keys[GLFW_KEY_D])
		camera->processKeyboard(RIGHT, deltaTime);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	if (key >= 0 && key < 1024) {
		if (action == GLFW_PRESS)
			keys[key] = true;
		else if (action == GLFW_RELEASE)
			keys[key] = false;
	}
}

void mouseCallback(GLFWwindow* window, double xpos, double ypos) {
	if (firstMouse) {
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	GLfloat xoffset = xpos - lastX;
	GLfloat yoffset = lastY - ypos;

	lastX = xpos;
	lastY = ypos;

	camera->processMouse(xoffset, yoffset);
}
