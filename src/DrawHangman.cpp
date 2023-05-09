//
// Created by aadarshadhakalg on 5/9/23.
//
#include <cmath>
#include "DrawHangman.hpp"

void drawBar() {
    glBegin(GL_LINES);
    glVertex2f(-0.5, 0.5);
    glVertex2f(-0.8, 0.5);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.8, 0.5);
    glVertex2f(-0.8, -0.6);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.9, -0.6);
    glVertex2f(-0.7, -0.6);
    glEnd();
}

void drawRope() {
    glBegin(GL_LINES);
    glVertex2f(-0.6, 0.5);
    glVertex2f(-0.6, 0.3);
    glEnd();
}

void drawHead() {
    int i;
    int lineAmount = 100; //# of triangles used to draw circle

    //GLfloat radius = 0.8f; //radius
    GLfloat twicePi = 2.0f * 22 / 7;

    glBegin(GL_LINE_LOOP);
    for(i = 0; i <= lineAmount;i++) {
        glVertex2f(
                -0.6 + (0.1 * cos(i *  twicePi / lineAmount)),
                0.2 + (0.1* sin(i * twicePi / lineAmount))
        );
    }
    glEnd();
}

void drawBody() {
    glBegin(GL_LINES);
    glVertex2f(-0.6, 0.1);
    glVertex2f(-0.6, -0.3);
    glEnd();
}

void drawLeftHand() {
    glBegin(GL_LINES);
    glVertex2f(-0.6, 0.0);
    glVertex2f(-0.7, -0.1);
    glEnd();
}

void drawRightHand() {
    glBegin(GL_LINES);
    glVertex2f(-0.6, 0.0);
    glVertex2f(-0.5, -0.1);
    glEnd();
}

void drawLeftLeg() {
    glBegin(GL_LINES);
    glVertex2f(-0.6, -0.3);
    glVertex2f(-0.7, -0.4);
    glEnd();
}

void drawRightLeg() {
    glBegin(GL_LINES);
    glVertex2f(-0.6, -0.3);
    glVertex2f(-0.5, -0.4);
    glEnd();
}

