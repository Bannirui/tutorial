#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "callback.h"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

/**
 * GLSL(OpenGL Shading Language) 跑在GPU上
 * 语法跟C相似
 * 版本声明
 * <ul>
 *   <li>330代表OpenGL3.3</li>
 *   <li>420代表OpenGL4.2</li>
 * </ul>
 */
const char* vertexShaderSource = "#version 330 core\n"
								 "layout (location = 0) in vec3 aPos;\n"
								 "void main()\n"
								 "{\n"
								 "    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
								 "}\0";

// colors in computer graphics are represented as an array of 4 values
// the red, green, blue and alpha(opacity) component
// RGBA
// set the strength of each component to a value between 0.0 and 1.0f
const char* fragmentShaderSource = "#version 330 core\n"
								   "out vec4 FragColor;\n"
								   "void main()\n"
								   "{\n"
								   "    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
								   "}\n\0";

int main(int argc, char** argv)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (!window)
	{
		std::cout << "Failed to create GLFW window\n";
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD\n";
		return -1;
	}
	// create a shader object
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	/**
	 * glShaderSource函数 takes the shader object to compile
	 * <ul>
	 *   <li>参数1 shader object</li>
	 *   <li>参数2 how many strings we're passing as source code, only one</li>
	 *   <li>参数3 is the actual source code of vertex shader</li>
	 * </ul>
	 */
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	int success;
	char infoLog[512];
	// check if compilation was successful
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << "\n";
	}
	// fragment shader is the second and final shader we're going to create for rendering a triangle
	// the fragment shader is all about calculating the color output of your pixels
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog;
	}
	// get a program object
	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << "\n";
	}
	// delete the shader objects once we've linked them into the program object, on longer need them anymore
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
    // 3D坐标 三角形的三个顶点的三维坐标
	float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f
	};
	// 通过VBO(vertex buffer objects)管理内存
	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	// glGenBuffers函数生成唯一的buffer编号id
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	// 绑定buffer
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	/**
	 * 将用户自定义数据拷贝到GPU buffer中
	 * <ul>
	 *   <li>参数1 想将数据拷贝到什么类型的buffer中</li>
	 *   <li>参数2 需要拷贝多大字节的数据到buffer中</li>
	 *   <li>参数3 实际要拷贝的数据</li>
	 *   <li>参数4 想要graphics card如何管理这些数据 有3种类型
	 *     <ul>
	 *       <li>GL_STREAM_DRAW 一次设置较少使用次数</li>
	 *       <li>GL_STATIC_DRAW 一次设置多次使用</li>
	 *       <li>GL_DYNAMIC_DRAW 多次设置多次使用</li>
	 *     </ul>
	 *   </li>
	 * </ul>
	 */
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		// 类型
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);
	glfwTerminate();
	return 0;
}