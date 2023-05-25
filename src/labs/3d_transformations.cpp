#include <iostream>
#include <GLFW/glfw3.h>
#include "cube_transformation_util.h"
#include <unistd.h>


vector<vector<float>> vertices = {
        {-0.5f,0.5f,0.5f},
        {0.5f,0.5f,0.5f},
        {0.5f,-0.5f,0.5f},
        {-0.5f,-0.5f,0.5f},

        {-0.5f,0.5f,-0.5f},
        {0.5f,0.5f,-0.5f},
        {0.5f,-0.5f,-0.5f},
        {-0.5f,-0.5f,-0.5f},
};

void face(vector<float> a, vector<float> b, vector<float> c, vector<float> d){


    // Convert Vector Types to Array Types
    float A[a.size()];
    std::copy(a.begin(), a.end(), A);
    float B[b.size()];
    std::copy(b.begin(), b.end(), B);
    float C[c.size()];
    std::copy(c.begin(), c.end(), C);
    float D[d.size()];
    std::copy(d.begin(), d.end(), D);


    glBegin(GL_QUADS);
    glVertex3fv(A);
    glVertex3fv(B);
    glVertex3fv(C);
    glVertex3fv(D);
    glEnd();
}

void drawPyramid(vector<vector<float>> &vertices){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,0,0);
    face(vertices[0],vertices[1],vertices[2],vertices[3]); // Front Face

    glColor3f(0,1,0);
    face(vertices[4],vertices[5],vertices[6],vertices[7]); // Back Face

    glColor3f(0,0,1);
    face(vertices[0],vertices[3],vertices[7],vertices[4]); // Left Face

    glColor3f(1,0,1);
    face(vertices[1],vertices[2],vertices[6],vertices[5]); // Right Face


    glColor3f(1,1,0);
    face(vertices[0],vertices[1],vertices[5],vertices[4]); // Top Face

    glColor3f(0,1,1);
    face(vertices[3],vertices[2],vertices[6],vertices[7]); // Bottom Face

    glEnd();
    glFlush();
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

    glEnable(GL_DEPTH_TEST);

    //Translate
    translateCube(vertices,0.1,0.1,-0.5);



    // Scale
    scaleCube(vertices, 0.5,0.5,0.5);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        // Rotate
        usleep(10000);
        rotateY(vertices, 0.0001);
        rotateX(vertices, 0.0001);
        rotateZ(vertices, 0.0001);

        drawPyramid(vertices);
        // Reset transformations
        glLoadIdentity();


        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}