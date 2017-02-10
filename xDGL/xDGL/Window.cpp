#include "Window.h"

Window::Window(void(*keyboardCallback)(GLFWwindow*, int, int, int, int), void(*mouseCallback)(GLFWwindow*, double, double))
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	glfwWindowHint(GLFW_SAMPLES, 4);

	window = glfwCreateWindow(WIDTH, HEIGHT, "xDGL", nullptr , nullptr);

	if (window == nullptr)
	{
		std::cout << "FAILED TO INITIALIZE WINDOW OBJECT!!!" << std::endl;
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, keyboardCallback);
	glfwSetCursorPosCallback(window, mouseCallback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	//wireframe danksta
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	glewExperimental = GL_TRUE;
	glewInit();
	glViewport(0, 0, 800, 600);

	glEnable(GL_DEPTH_TEST);
}

GLFWwindow* Window::getWindow() {
	return window;
}

bool Window::isClose() {
	if (glfwWindowShouldClose(window))
	{
		return true;
	}
	else
	{
		return false;
	}
}