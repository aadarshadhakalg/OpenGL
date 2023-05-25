//
// Created by aadarshadhakalg on 5/25/23.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Translates a cube on x, y and z axis
void translateCube(std::vector<std::vector<float>> &vertices, float x, float y, float z) {
    for (int i = 0; i < 8; i++) {
        vertices[i][0] += x;
        vertices[i][1] += y;
        vertices[i][2] += z;
    }
}

// Rotates a cube on the x-axis by the given angle.
void rotateZ(vector<vector<float>> &vertices, float angle) {
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
void rotateY(vector<vector<float>> &vertices, float angle) {
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
void rotateX(vector<vector<float>> &vertices, float angle) {
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