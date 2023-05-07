#include <restc-cpp/restc-cpp.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <display_text.hpp>
#include <shader.hpp>

typedef void (*GameScreen)(GLFWwindow *window);

GameScreen *gameScreen;

void process_keys(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
    {
        std::cout << "Start The Game" << std::endl;
    }
}

int main()
{

    GLFWwindow *window;

    if (!glfwInit())
    {
        std::cout << "Cannot Create Window" << std::endl;
        return -1;
    }

    window = glfwCreateWindow(1600, 1200, "Hangman", nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "Error Initializing GLEW" << std::endl;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    // OpenGL State
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    // CREATING VAO and VBA
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    // glBufferData(GL_ARRAY_BUFFER, 6);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        DisplayText* displayText = new DisplayText();
        Shader shader = displayText->compile_text_shaders();
        displayText->render_text(shader, "This is sample text", 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
        displayText->render_text(shader, "(C) LearnOpenGL.com", 540.0f, 570.0f, 0.5f, glm::vec3(0.3, 0.7f, 0.9f));



        glfwSwapBuffers(window);
        glfwPollEvents();
        glfwSetKeyCallback(window, process_keys);
    }

    glfwTerminate();
    return 0;
}