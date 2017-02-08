#include "Window.h"
#include "ResourceManager.h"
#include "Shader.h"

#include "Camera.h"

#include "Triangle.h"
#include "Plane.h"
#include "Cube.h"
#include "LightSource.h"

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
	Shader shader = ResourceManager::LoadShader("shaders/vertex/specular.vs", "shaders/fragment/specular.fs", nullptr, "objectShader");

	Triangle* triangle = new Triangle();
	Plane* plane = new Plane();
	Cube* cube = new Cube();
	LightSource* light = new LightSource();

	while (!window->isClose()) {
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();
		doMovement();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		//triangle->Draw(coShader, camera);
		cube->Draw(shader, camera, light->getPosition());
		light->Draw(lampShader, camera);
		//plane->Draw(coShader, camera);

		glfwSwapBuffers(window->getWindow());
	}

	glfwTerminate();

	return 0; // Pamiętajcie dzieciaczki. Nie macie kopi zapasowej - nie istniejecie.
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
