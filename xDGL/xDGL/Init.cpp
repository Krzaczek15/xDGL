#include "Window.h"

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
void mouseCallback(GLFWwindow* window, double xpos, double ypos);
void doMovement();


bool keys[1024];

int main() {

	Window* window = new Window(keyCallback, mouseCallback);

	while (!window->isClose()) {
		glfwPollEvents();
		doMovement();

		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwSwapBuffers(window->getWindow());
	}

	glfwTerminate();

	return 0; // Pamiêtajcie dzieciaczki. Nie macie kopi zapasowej - nie istniejecie.
}

void doMovement() {

}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {

}

void mouseCallback(GLFWwindow* window, double xpos, double ypos) {

}
