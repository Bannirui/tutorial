// glad在glfw之前 因为glfw依赖glad头文件中的部分内容
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(int argc, char** argv)
{
	std::cout << "hello world" << std::endl;
	return 0;
}