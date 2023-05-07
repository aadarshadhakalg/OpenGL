#include <restc-cpp/restc-cpp.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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

    // gameScreen = startScreen();
    if(glewInit() != GLEW_OK){
        std::cout << "Error Initializing GLEW" << std::endl;
    }

    std::cout << glGetString(GL_VERSION) << std::endl;

    // CREATING VAO and VBA
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER,buffer);
    // glBufferData(GL_ARRAY_BUFFER, 6);



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