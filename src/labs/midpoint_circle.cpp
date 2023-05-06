//
// Created by Aadarsha Dhakal on 24/04/2023.
//
#include <stdio.h>
#include <iostream>
#include <GL/gl.h>
#include <Gl/glu.h>
#include <GLFW/glfw3.h>

using namespace std;

int pntX1, pntY1, r;

void plot(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x+pntX1, y+pntY1);
    glEnd();
}

void midPointCircleAlgo()
{
    int x = 0;
    int y = r;
    float decision = 5/4 - r;
    plot(x, y);

    while (y > x)
    {
        if (decision < 0)
        {
            x++;
            decision += 2*x+1;
        }
        else
        {
            y--;
            x++;
            decision += 2*(x-y)+1;
        }
        plot(x, y);
        plot(x, -y);
        plot(-x, y);
        plot(-x, -y);
        plot(y, x);
        plot(-y, x);
        plot(y, -x);
        plot(-y, -x);
    }

}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    midPointCircleAlgo();

    glFlush ();
}


void myInit (void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char ** argv) {

    cout << "Enter the coordinates of the center:\n\n" << endl;

    cout << "X-coordinate   : "; cin >> pntX1;
    cout << "\nY-coordinate : "; cin >> pntY1;
    cout << "\nEnter radius : "; cin >> r;

    GLFWwindow* window;

    //Initialize the library:
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(500, 500, "Midpoint Circle Algorithm", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    //Loop until the window is closed:
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        myInit ();
        display();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();

    return 0;

}