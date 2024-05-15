//
// Created by dingrui on 5/15/24.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "callback.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	std::cout << "resize window: w=" << width << ", h=" << height << "\n";
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		std::cout << "Ready to escape\n";
		glfwSetWindowShouldClose(window, true);
	}
}
