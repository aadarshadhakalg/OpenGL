#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <DisplayText.hpp>
#include <Navigator.hpp>
#include <StartScreen.hpp>
#include <GameScreen.hpp>
#include "InputHandlers.hpp"


int main()
{

    GLFWwindow *window;

    if (!glfwInit())
    {
        std::cout << "Cannot Create Window" << std::endl;
        return -1;
    }


    // Setup Window Full Screen
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    glfwWindowHint(GLFW_RED_BITS, mode->redBits);
    glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
    glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
    glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
    window = glfwCreateWindow(mode->width, mode->height, "Hangman", monitor, nullptr);
    float sx = 2.0f/ mode->width;
    float sy = 2.0f/ mode->height;

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

    // Initiate Navigator Object
    auto startScreen = new StartScreen();
    auto* gameNavigator = Navigator::getInstance();
    gameNavigator->setCurrentScreen(startScreen);

    // From Text Library
    // Credit: https://gitlab.com/wikibooks-opengl/modern-tutorials/-
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Create DisplayText Object ( Singleton )
    auto displayText = DisplayText::getInstance();
    displayText->fontfilename = "../fonts/Alter.ttf";

    // Init Display Text Resources (FreeType and Shader Compilation)
    if(displayText->init_resources()) {
        while (!glfwWindowShouldClose(window)) {
            glClear(GL_COLOR_BUFFER_BIT);

            auto screen = gameNavigator->getCurrentScreen();
            screen->display();

            glfwSwapBuffers(window);
            glfwPollEvents();

            // Set Input process
            glfwSetKeyCallback(window, processInputKeys);
        }
    }

    displayText->free_resources();

    glfwTerminate();
    return 0;
}