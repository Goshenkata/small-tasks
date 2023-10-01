#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Shader.h"
#include <cmath>
#include <iostream>
#include <cmath>

void frameBufferSizeCallback([[maybe_unused]]GLFWwindow *window, int width, int height);

void processInput(GLFWwindow *pWwindow);


int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(800, 500, "OPENGL", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Error creating window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to init GLAD";
        glfwTerminate();
        return -1;
    }

    auto vertexShaderPath = "/home/cirno/Projects/small-tasks/cpp/opengl/traingle2/shader.vert";
    auto fragmentShaderPath = "/home/cirno/Projects/small-tasks/cpp/opengl/traingle2/shader.frag";

    Shader shader(vertexShaderPath, fragmentShaderPath);

    float vertexData[]{0.0f, 0.5f, 0.0f,      1.0, 0.0, 0.0,
                       -0.5f, -0.5f, 0.0f,    0.0, 1.0, 0.0,
                       0.5f, -0.5f, 0.0f, 0.0, 0.0, 1.0
    };
    unsigned int VAO, VBO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, false, sizeof(float) * 6, (void *) 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, false, sizeof(float) * 6, (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        glBindVertexArray(VAO);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}

void processInput(GLFWwindow *pWwindow) {
    if (glfwGetKey(pWwindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(pWwindow, true);
    }
}


void frameBufferSizeCallback([[maybe_unused]]GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}
