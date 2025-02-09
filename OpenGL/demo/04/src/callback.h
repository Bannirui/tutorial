//
// Created by dingrui on 5/15/24.
//

#ifndef _CALLBACK_H_
#define _CALLBACK_H_

struct GLFWwindow;

/* window大小发生变化时回调函数 */
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

void processInput(GLFWwindow *window);

#endif //_CALLBACK_H_
