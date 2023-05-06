#include <iostream>
#include <GLFW/glfw3.h>

void drawPyramid(){
    
}

int main(){
    GLFWwindow* window;


    if(!glfwInit()){
        std::cout << "Error" << std::endl;
        return -1;
    }

    window = glfwCreateWindow(800,600,"3D Transformations",nullptr,nullptr);

    if(!window){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        drawPyramid();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    



    glfwTerminate();
    return 0;
}