#include<stdio.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <GL/glu.h>


float x1, y1, x2, y2;


void myInit (void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}


void draw_pixel(float x, float y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void display() {
    float dx, dy, i, e;
    float incx, incy, inc1, inc2;
    float x,y;

    dx = x2-x1;
    dy = y2-y1;

    if (dx < 0) dx = -dx;
    if (dy < 0) dy = -dy;
    incx = 1;
    if (x2 < x1) incx = -1;
    incy = 1;
    if (y2 < y1) incy = -1;
    x = x1; y = y1;
    if (dx > dy) {
        draw_pixel(x, y);
        e = 2 * dy-dx;
        inc1 = 2*(dy-dx);
        inc2 = 2*dy;
        for (i=0; i<dx; i++) {
            if (e >= 0) {
                y += incy;
                e += inc1;
            }
            else
                e += inc2;
            x += incx;
            draw_pixel(x, y);
        }

    } else {
        draw_pixel(x, y);
        e = 2*dx-dy;
        inc1 = 2*(dx-dy);
        inc2 = 2*dx;
        for (i=0; i<dy; i++) {
            if (e >= 0) {
                x += incx;
                e += inc1;
            }
            else
                e += inc2;
            y += incy;
            draw_pixel(x, y);
        }
    }
}

int main(int argc, char **argv) {

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

    window = glfwCreateWindow(500, 500, "BLA Algorithm", NULL, NULL);

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