#include "Window.h"
#include "ResourceManager.h"
#include "Shader.h"

#include "Triangle.h"
#include "Plane.h"
#include "Cube.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouseCallback(GLFWwindow* window, double xpos, double ypos);
void doMovement();

bool keys[1024];

int main() {

	Window* window = new Window(keyCallback, mouseCallback);

	Shader testShader = ResourceManager::LoadShader("shaders/vertex/test.vs", "shaders/fragment/test.fs", nullptr, "testShader");
	Shader coShader = ResourceManager::LoadShader("shaders/vertex/coVertex.vs", "shaders/fragment/coFragment.fs", nullptr, "coShader");


	Triangle* triangle = new Triangle();
	Plane* plane = new Plane();
	Cube* cube = new Cube();

	while (!window->isClose()) {
		glfwPollEvents();
		doMovement();

		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		
		//triangle->Draw(testShader);
		cube->Draw(coShader);
		
		//plane->Draw(testShader);


		glfwSwapBuffers(window->getWindow());
	}

	glfwTerminate();

	return 0; // Pamiêtajcie dzieciaczki. Nie macie kopi zapasowej - nie istniejecie.
}

void doMovement() {

}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

void mouseCallback(GLFWwindow* window, double xpos, double ypos) {

}
