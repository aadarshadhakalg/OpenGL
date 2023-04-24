//
// Created by Aadarsha Dhakal on 24/04/2023.
//
#include<stdlib.h>
#include<stdio.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>

float x1, x2, y1, y2;


void draw_pixel(float x, float y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}


void display() {
    float dy, dx, step, x, y, k, Xin, Yin;
    dx = x2 - x1;
    dy = y2 - y1;
    if (abs(dx) > abs(dy)) {
        step = abs(dx);
    } else
        step = abs(dy);
    Xin = dx / step;
    Yin = dy / step;
    x = x1;
    y = y1;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    for (k = 1; k <= step; k++) {
        x = x + Xin;
        y = y + Yin;
        draw_pixel(x,y);
    }
    glFlush();
}

void myInit (void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char ** argv) {

    printf("Value of x1 : ");
    scanf("%f", & x1);
    printf("Value of y1 : ");
    scanf("%f", & y1);
    printf("Value of x2 : ");
    scanf("%f", & x2);
    printf("Value of y2 : ");
    scanf("%f", & y2);

    GLFWwindow* window;

    //Initialize the library:
    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(800, 600, "DDA Algorithm", NULL, NULL);

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