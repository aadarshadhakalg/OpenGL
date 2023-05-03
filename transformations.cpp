#include <iostream>
#include <GLFW/glfw3.h>
#include <Eigen/Dense>
#include <math.h>

typedef Eigen::Matrix<float, 3, 3> Matrix3f;
typedef Eigen::Matrix<float, 3, 1> Vector3f;

// Degree to Radian Conversion
float toRad(float deg){
    return deg*3.14159/180;
}


// Initialize Triangle Vector
Matrix3f initialTriangle {{-0.85f,0.85f,1.0f},
                 {-1.0f, 0.45f, 1.0f},
                 {-0.70f, 0.45f, 1.0f}};
                
// transformed Triangle
Matrix3f transformedTriangle;


// Translate Triangle
int translate(float x, float y, Matrix3f triangle){
    Matrix3f translationMatrix { { 1.0f, 0,x }, { 0, 1.0f, y }, { 0, 0, 1.0f } };
    
    for (int i = 0; i < 3; i++)
    {
        transformedTriangle.row(i) = translationMatrix * triangle.row(i).transpose();
    }
    return 1;
}


// Scale Triangle
int scale(float x, float y, Matrix3f triangle){
    Matrix3f translationMatrix { { x, 0,0 }, { 0, y, 0 }, { 0, 0, 1.0f } };
    
    for (int i = 0; i < 3; i++)
    {
        transformedTriangle.row(i) = translationMatrix * triangle.row(i).transpose();
    }
    return 1;
}


// Rotate Triangle
int rotate(float deg, Matrix3f triangle){
    deg = toRad(deg);
    Matrix3f translationMatrix { { cos(deg), -sin(deg),0 }, { sin(deg), cos(deg), 0 }, { 0, 0, 1.0f } };
    
    for (int i = 0; i < 3; i++)
    {
        transformedTriangle.row(i) = translationMatrix * triangle.row(i).transpose();
    }
    return 1;
}


void clearWindow()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void drawTriangle(Matrix3f a)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < 3; i++)
    {
        glVertex2f(a(i,0), a(i,1));
    }
    glEnd();
}

int main()
{
    GLFWwindow *window;

    if (!glfwInit())
    {
        return -1;
    }

    window = glfwCreateWindow(800, 600, "Translations", nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        clearWindow();

        drawTriangle(initialTriangle);
        translate(1.5,0.0,initialTriangle);
        rotate(180,transformedTriangle);
        scale(1.2,1.2,transformedTriangle);
        drawTriangle(transformedTriangle);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}