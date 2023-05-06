#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

const float PI = 3.14159;

void display(){

    // Upper Red Traingle
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(0.0f, 0.45f);
    glVertex2f(0.5f, 0.45f);
    glEnd();

    // Lower Red Traingle
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0f, 0.625f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glEnd();

    // Border Lines
    glLineWidth(4.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0f, 1.0f);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(0.5f, 0.0f);
    glVertex2f(0.15f, 0.45f);
    glVertex2f(0.5f, 0.45f);
    glEnd();



    // SUN
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    float x, y;
    float radius = 0.08f;
    float center_x = 0.15f, center_y = 0.15f;
    glVertex2f(center_x, center_y);
    for (int i = 0; i <= 32; i++)
    {
        x = center_x + radius * cos(i);
        y = center_y + radius * sin(i);
        glVertex2f(x, y);
    }
    glEnd();



    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
    float a, b;
    float radius1 = 0.08f;
    float center_a = 0.15f, center_b = 0.6f;
    glVertex2f(center_a, center_b);
    for (int i = 0; i <= 32; i++)
    {
        a = center_a + radius1 * cos(i);
        b = center_b + radius1 * sin(i);
        glVertex2f(a, b);
    }
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLE_FAN);
    float radius2 = 0.06f;
    float center_c = 0.15, center_d = 0.65;
    glVertex2f(center_c, center_d);
    for (int i = 0; i <= 32; i++)
    {
        a = center_c + radius2 * cos(i);
        b = center_d + radius2 * sin(i);
        glVertex2f(a, b);
    }
    glEnd();
}

int main()
{
    GLFWwindow* window;

    //Initialize the library:
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(800, 600, "Nepal FLag", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    //Loop until the window is closed:
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        display();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;
}