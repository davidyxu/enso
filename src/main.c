#include <stdio.h>
#include <stdlib.h>
#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#define OPENGL_VERSION_MAJOR 3
#define OPENGL_VERSION_MINOR 2

#define RANDOM_FLOAT (float) rand() / ((float) RAND_MAX + 1)

const static int WIDTH = 600, HEIGHT = 600;

int main(int argc, char **argv)
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_VERSION_MAJOR);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_VERSION_MINOR);

    // hint for os x to use newer version of OpenGL
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Enso", NULL, NULL);
    if (!window) {
        fprintf(stderr, "Failed to crate GLFW window\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (gl3wInit()) {
        fprintf(stderr, "failed to initialize OpenGL\n");
        glfwTerminate();
        return -1;
    }

    if (!gl3wIsSupported(OPENGL_VERSION_MAJOR, OPENGL_VERSION_MINOR)) {
        fprintf(stderr, "OpenGL %d.%d is not supported\n", OPENGL_VERSION_MAJOR, OPENGL_VERSION_MINOR);
        glfwTerminate();
        return -1;
    }

    while(!glfwWindowShouldClose(window)) {
        glClearColor(RANDOM_FLOAT, RANDOM_FLOAT, RANDOM_FLOAT, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
