#pragma once

#include <glew.h>
#include <glfw3.h>

#include <iostream>

class Window
{
private:
	const int WIDTH  = 1024;
	const int HEIGHT = 768;
public:
	GLFWwindow* window;

	Window(void(*keyboardCallback)(GLFWwindow*, int, int, int, int), void(*mouseCallback)(GLFWwindow*, double, double));

	GLFWwindow* getWindow();

	bool isClose();
};

