#include <iostream>
#include <GLFW/glfw3.h>


int main(){
    GLFWwindow* window;

    if(!glfwInit()){
        return -1;
    }

    window = glfwCreateWindow(600,400,"Cohen Sutherland",nullptr,nullptr);

    if(!window){
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while(!glfwWindowShouldClose(window)){

    }

    glfwTerminate();
    return -1;
}