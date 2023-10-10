#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Shader.h"
#include <iostream>
#include "stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void frameBufferSizeCallback([[maybe_unused]]GLFWwindow *window, int width, int height);

void processInput(GLFWwindow *pWwindow, Shader* shader);
float visibility = 0.2f;


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

    auto vertexShaderPath = "/home/cirno/Projects/small-tasks/cpp/opengl/transform/shader.vert";
    auto fragmentShaderPath = "/home/cirno/Projects/small-tasks/cpp/opengl/transform/shader.frag";

    Shader shader(vertexShaderPath, fragmentShaderPath);

    float vertices[] = {
            // positions          // colors           // texture1 coords
            0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
            0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f,    // top left
            0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // top right
            0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // bottom right
            -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // bottom left
            -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // top left
    };
    unsigned int indices[] = {
        0, 1,3,
        1,2,3,
        4,5,6,
        5,5,6
    };
    unsigned int VAO, VBO, EBO;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    int stride = sizeof(float) * 8;
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void *) 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void *) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (void *) (6 * sizeof(float)));
    glEnableVertexAttribArray(2);


    // Texture
    unsigned int texture1, texture2;
    glGenTextures(1, &texture1);
    glGenTextures(1, &texture2);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    //parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nChannels;
    auto filename = "/home/cirno/Downloads/container.jpg";
    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(filename,&width, &height, &nChannels, 0);
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0,GL_RGB, GL_UNSIGNED_BYTE,  data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cerr << "Error loading image\n";
    }
    stbi_image_free(data);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);

    auto filename2 = "/home/cirno/Downloads/awesomeface.png";
    unsigned char* data2 = stbi_load(filename2,&width, &height, &nChannels, 0);
    if (data2) {
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0,GL_RGBA, GL_UNSIGNED_BYTE,  data2);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cerr << "Error loading image\n";
    }
    stbi_image_free(data2);

    shader.use();
    shader.setInt("texture2", 1);

    while (!glfwWindowShouldClose(window)) {
        processInput(window, &shader);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);

        // render container
        shader.setFloat("visibility", visibility);
        glBindVertexArray(VAO);

        glm::mat4 trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
        trans = glm::rotate(trans, (float) glfwGetTime(), glm::vec3(0.0, 0.0,1.0));
        shader.setMatrix4f("transform", glm::value_ptr(trans));
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        //second
        trans = glm::mat4(1.0f);
        trans = glm::translate(trans, glm::vec3(-0.5f, 0.5f, 0.0f));
        float scale = (float) glm::sin(glfwGetTime());
        trans = glm::scale(trans,glm::vec3(scale, scale, 1.0f));
        shader.setMatrix4f("transform", glm::value_ptr(trans));
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);


        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    return 0;
}

void processInput(GLFWwindow *pWwindow, Shader* shader) {
    if (glfwGetKey(pWwindow, GLFW_KEY_UP) == GLFW_PRESS) {
        visibility += 0.01f;
        if (visibility >= 1.0f) {
            visibility = 1.0f;
        }
    }

    if (glfwGetKey(pWwindow, GLFW_KEY_DOWN) == GLFW_PRESS) {
        visibility -= 0.01f;
        if (visibility <= 0.0f) {
            visibility = 0.0f;
        }
    }
    if (glfwGetKey(pWwindow, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(pWwindow, true);
    }
}


void frameBufferSizeCallback([[maybe_unused]]GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}
