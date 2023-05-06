#include <iostream>
#include <GLFW/glfw3.h>
#include <restc-cpp/restc-cpp.h>

typedef void (* GameScreen)(GLFWwindow* window);


GameScreen* gameScreen;

void process_keys(GLFWwindow* window, int key, int scancode, int action,int mods){
    if(key == GLFW_KEY_SPACE && action == GLFW_PRESS){
        std::cout << "Start The Game" << std::endl;
    }
}


int main(){

    GLFWwindow* window;

    if(!glfwInit()){
        std::cout << "Cannot Create Window" << std::endl;
        return -1;
    }

    window = glfwCreateWindow(1600,1200,"Hangman",nullptr,nullptr);

    if(!window){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gameScreen = startScreen();

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        void startScreen();

        glfwSwapBuffers(window);
        glfwPollEvents();
        glfwSetKeyCallback(window,process_keys);
    }
    

    glfwTerminate();
    return 0;
}