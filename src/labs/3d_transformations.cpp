#include <iostream>
#include <GLFW/glfw3.h>
#include <vector>
#include <cmath>
#include <unistd.h>


std::vector<std::vector<float>> vertices = {
        {-0.5f,0.5f,0.5f},
        {0.5f,0.5f,0.5f},
        {0.5f,-0.5f,0.5f},
        {-0.5f,-0.5f,0.5f},

        {-0.5f,0.5f,-0.5f},
        {0.5f,0.5f,-0.5f},
        {0.5f,-0.5f,-0.5f},
        {-0.5f,-0.5f,-0.5f},
};


// Translates a cube on x, y and z axis
void translateCube(std::vector<std::vector<float>> &vertices, float x, float y, float z) {
    for (int i = 0; i < 8; i++) {
        vertices[i][0] += x;
        vertices[i][1] += y;
        vertices[i][2] += z;
    }
}

// Rotates a cube on the x-axis by the given angle.
void rotateZ(std::vector<std::vector<float>> &vertices, float angle) {
    angle = angle * 180/M_PI;
    for (int i = 0; i < 8; i++) {
        float x = vertices[i][0];
        float y = vertices[i][1];
        float z = vertices[i][2];

        vertices[i][0] = x * cos(angle) - y * sin(angle);
        vertices[i][1] = x * sin(angle) + y * cos(angle);
        vertices[i][2] = z;
    }
}

// Rotates a cube on the y-axis by the given angle.
void rotateY(std::vector<std::vector<float>> &vertices, float angle) {
    angle = angle * 180/M_PI;

    for (int i = 0; i < 8; i++) {
        float x = vertices[i][0];
        float y = vertices[i][1];
        float z = vertices[i][2];

        vertices[i][0] = x * cos(angle) + z * sin(angle);
        vertices[i][1] = y;
        vertices[i][2] = -x * sin(angle) + z * cos(angle);
    }
}

// Rotates a cube on the z-axis by the given angle.
void rotateX(std::vector<std::vector<float>> &vertices, float angle) {
    angle = angle * 180/M_PI;

    for (int i = 0; i < 8; i++) {
        float x = vertices[i][0];
        float y = vertices[i][1];
        float z = vertices[i][2];

        vertices[i][0] = x;
        vertices[i][1] = y * cos(angle) - z * sin(angle);
        vertices[i][2] = y * sin(angle) + z * cos(angle);
    }
}

// Scales a cube by scaling factors sx, xy and sz
void scaleCube(std::vector<std::vector<float>> &vertices, float sx, float sy, float sz) {
    for (int i = 0; i < 8; i++) {
        vertices[i][0] *= sx;
        vertices[i][1] *= sy;
        vertices[i][2] *= sz;
    }
}

void face(std::vector<float> a, std::vector<float> b, std::vector<float> c, std::vector<float> d){


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

void drawPyramid(std::vector<std::vector<float>> &vertices){
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