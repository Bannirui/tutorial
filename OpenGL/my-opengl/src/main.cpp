// glad在glfw之前 因为glfw依赖glad头文件中的部分内容
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

typedef int i32;
typedef unsigned int u32;

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// settings
#define SCR_WIDTH 800
#define SCR_HEIGHT 600

const char *vertexShaderSource = "#version 330 core\n"
								 "layout (location = 0) in vec3 aPos;\n"
								 "void main()\n"
								 "{\n"
								 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
								 "}\0";

const char *fragmentShaderSource = "#version 330 core\n"
								   "out vec4 FragColor;\n"
								   "void main()\n"
								   "{\n"
								   "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
								   "}\n\0";

int main(int argc, char **argv) {
  /**
   * GLFW
   *   - initialize
   *   - configure
   */
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  // 苹果系统需要单独配置compatible特性
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

  // glfw window creation
  GLFWwindow *window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "my-OpenGL", nullptr, nullptr);
  if (window == nullptr) {
	std::cout << "Failed to create GLFW window" << std::endl;
	glfwTerminate();
	return -1;
  }
  // tell GLFW to make the context of our window the main context on the current thread
  glfwMakeContextCurrent(window);
  // register a callback function on the window that gets called each time the window is resized
  // tell GLFW we want to call this function on every window resize by registering it
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  // glad: load all OpenGL function pointers
  // initialize GLAD before call any OpenGL function
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
	std::cout << "Failed to initialize GLAD" << std::endl;
	return -1;
  }

  // vertex shader
  u32 vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
  glCompileShader(vertexShader);
  // check for shader compile errors
  i32 success;
  char infoLog[512];
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
	glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
  }
  // fragment shader
  unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
  glCompileShader(fragmentShader);
  // check for shader compile errors
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
	glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
	std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
  }
  // link shaders
  u32 shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  // check for linking errors
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
	glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
	std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
  }
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  /**
   * set up vertex data
   * buffers
   * configure vertex attributes
   */
  float vertices[] = {
	  0.5f, 0.5f, 0.0f, // top right
	  0.5f, -0.5f, 0.0f, // bottom right
	  -0.5f, -0.5f, 0.0f, // bottom left
	  -0.5f, 0.5f, 0.0f // top left
  };
  u32 indices[] = {
	  0, 1, 3, // first triangle
	  1, 2, 3 // second triangle
  };
  u32 VBO, VAO, EBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);
  // bind the vertex array object first
  // then bind and set vertex buffers
  // and then configure vertex attributes
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindVertexArray(0);

  // render loop
  // keep on running until we tell GLFW to stop
  // check at the start of each loop iteration if GLFW has been instructed to close
  while (!glfwWindowShouldClose(window)) {
	// input, call function every iteration of the render loop
	processInput(window);
	// rendering commands here
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// draw triangle
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	// swap the color buffer(a large 2D buffer that contains color values for each pixel in GLFW window)
	// the buffer is used to render to during this render iteration and show as output to the screen
	glfwSwapBuffers(window);
	/**
	 * this function checks if any events are triggered
	 *   - keyboard input
	 *   - mouse movement events
	 * updates the window state, and calls the corresponding functions(callback function)
	 */
	glfwPollEvents();
  }
  // de-allocate all resources once they've outlived their purpose
  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);
  glDeleteProgram(shaderProgram);

  // as soon as we exit the render loop we would like to properly clean/delete all of GLFW resources that were allocated
  glfwTerminate();
  return 0;
}

// 窗口resize的回调函数
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  // make sure the viewport matches the new window dimensions
  glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
  // this function takes the window as input together with a key
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	glfwSetWindowShouldClose(window, true);
}