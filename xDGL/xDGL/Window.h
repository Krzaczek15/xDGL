#pragma once

#include <glew.h>
#include <glfw3.h>

#include <iostream>

class Window
{
private:
	const int WIDTH  = 800;
	const int HEIGHT = 600;
public:
	GLFWwindow* window;

	Window(void(*keyboardCallback)(GLFWwindow*, int, int, int, int), void(*mouseCallback)(GLFWwindow*, double, double));

	GLFWwindow* getWindow();

	bool isClose();
};

