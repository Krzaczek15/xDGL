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

Camera* camera = new Camera(glm::vec3(0.0f, 0.0f, 3.0f));

GLfloat lastX = 400, lastY = 300;
bool firstMouse = true;

glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

int main() {

	Window* window = new Window(keyCallback, mouseCallback);

	//Shader testShader = ResourceManager::LoadShader("shaders/vertex/test.vs", "shaders/fragment/test.fs", nullptr, "testShader");
	//Shader coShader = ResourceManager::LoadShader("shaders/vertex/coVertex.vs", "shaders/fragment/coFragment.fs", nullptr, "coShader");

	//Shader shader = ResourceManager::LoadShader("shaders/vertex/lightingShader.vs", "shaders/fragment/lightingShader.fs", nullptr, "objectShader");
	Shader lampShader = ResourceManager::LoadShader("shaders/vertex/lightingShader.vs", "shaders/fragment/lampShader.fs", nullptr, "xdobjectShader");
	
	//Shader shader = ResourceManager::LoadShader("shaders/vertex/phong.vs", "shaders/fragment/phong.fs", nullptr, "objectShader");
	//Shader shader = ResourceManager::LoadShader("shaders/vertex/specular.vs", "shaders/fragment/specular.fs", nullptr, "objectShader");

	//Shader shader = ResourceManager::LoadShader("shaders/vertex/specular.vs", "shaders/fragment/materialTest.fs", nullptr, "objectShader");
	Shader shader = ResourceManager::LoadShader("shaders/vertex/textureTest.vs", "shaders/fragment/textureTest.fs", nullptr, "objectShader");

	Triangle* triangle = new Triangle();
	Plane* plane = new Plane();
	LightSource* light = new LightSource();

	std::vector<Cube> cubes(10);
	std::vector<glm::vec3> cubesPositions = {
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(5.0f, 20.0f, 1.0f),
		glm::vec3(5.0f, 3.0f, 20.0f),

		glm::vec3(1.0f, 4.0f, 4.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),

		glm::vec3(5.0f, 0.0f, 1.0f),
		glm::vec3(5.0f, 7.0f, -2.0f),
		glm::vec3(2.0f, 5.0f, 5.0f),

		glm::vec3(15.0f, 12.0f, 3.0f)
	};


	ResourceManager::LoadTexture("textures/container.png", GL_FALSE, "diffuse");
	ResourceManager::LoadTexture("textures/specular.png", GL_FALSE, "specular");

	shader.Use();
	shader.setInteger("material.diffuse", 0);
	shader.setInteger("material.specular", 1);

	while (!window->isClose()) {
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();
		doMovement();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		shader.Use();

		glActiveTexture(GL_TEXTURE0);
		ResourceManager::GetTexture("diffuse").Bind();
		glActiveTexture(GL_TEXTURE1);
		ResourceManager::GetTexture("specular").Bind();

		for (int i = 0; i < cubes.size(); i++) {
			cubes.at(i).setPosition(cubesPositions.at(i)); //ZA WARUDO
			cubes.at(i).Draw(shader, camera, light->getPosition()); //TEMEEEE 
		}

		light->Draw(lampShader, camera);

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
