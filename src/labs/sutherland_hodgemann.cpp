#include <iostream>
#include <GLFW/glfw3.h>
#include <Eigen/Dense>
#include <algorithm>
#include <vector>

typedef Eigen::Matrix<float, 4, 2> ViewPort;
typedef Eigen::Matrix<float, 2, 2> Line;
typedef Eigen::Matrix<float, 1, 2> Point;
typedef Eigen::Matrix<float, 4, 2> Polygon;

const ViewPort VIEW_PORT{
    {-0.5f, -0.5f},
    {0.5f, -0.5f},
    {0.5f, 0.5f},
    {-0.5f, 0.5f}};

const Polygon initial{
    {-1.0f, -1.0f},
    {1.0f, -1.0f},
    {0.2f, 1.0f},
    {-0.2f, 1.0f},
};

std::vector<Point> clippedPolygon;

float xMax;
float xMin;
float yMax;
float yMin;

// Top - Below - Right - Left
int getRegionCode(Point l1, ViewPort viewPort)
{
    xMax = viewPort.col(0).maxCoeff();
    xMin = viewPort.col(0).minCoeff();
    yMax = viewPort.col(1).maxCoeff();
    yMin = viewPort.col(1).minCoeff();

    int regionCode = 0000;

    if (l1(1) > yMax)
    {
        regionCode += 8;
    }

    if (l1(1) < yMin)
    {
        regionCode += 4;
    }

    if (l1(0) > xMax)
    {
        regionCode += 2;
    }

    if (l1(0) < xMin)
    {
        regionCode += 1;
    }

    return regionCode;
}

void clipLine(Line l1, ViewPort viewPort)
{
    Point p1 = l1.row(0);
    Point p2 = l1.row(1);

    int p1RegionCode = getRegionCode(p1, viewPort);
    int p2RegionCode = getRegionCode(p2, viewPort);

    std::cout << p1RegionCode << std::endl;
    std::cout << p2RegionCode << std::endl;

    float slopeM = (p2(1) - p1(1)) / (p2(0) - p1(0));

    while (p1RegionCode != 0 || p2RegionCode != 0)
    {
        int res = p1RegionCode & p2RegionCode;

        if (res != 0)
        {

            if (p1RegionCode >= 8)
            {
                p1 = Point{p1(0), yMax};
                p1RegionCode = getRegionCode(p1, viewPort);
            }
            if (p1RegionCode >= 4)
            {
                p1 = Point{p1(0), yMin};
                p1RegionCode = getRegionCode(p1, viewPort);
            }
            if (p1RegionCode >= 2)
            {
                p1 = Point{xMax, p1(1)};
                p1RegionCode = getRegionCode(p1, viewPort);
            }

            if (p1RegionCode >= 1)
            {
                p1 = Point{xMin, p1(1)};
                p1RegionCode = getRegionCode(p1, viewPort);
            }

            if (p2RegionCode >= 8)
            {
                p2 = Point{p2(0), yMax};
                p2RegionCode = getRegionCode(p2, viewPort);
            }
            if (p2RegionCode >= 4)
            {
                p2 = Point{p2(0), yMin};
                p2RegionCode = getRegionCode(p2, viewPort);
            }
            if (p2RegionCode >= 2)
            {
                p2 = Point{xMax, p2(1)};
                p2RegionCode = getRegionCode(p2, viewPort);
            }

            if (p2RegionCode >= 1)
            {
                p2 = Point{xMin, p2(1)};
                p2RegionCode = getRegionCode(p2, viewPort);
            }

            continue;
        }

        else if (p1RegionCode != 0)
        {
            if (p1RegionCode >= 8)
            {
                float x = p1(0) + (yMax - p1(1)) / slopeM;
                p1 = Point{x, yMax};
            }
            else if (p1RegionCode >= 4)
            {
                float x = p1(0) + (yMin - p1(1)) / slopeM;
                p1 = Point{x, yMin};
            }
            else if (p1RegionCode >= 2)
            {
                float y = p1(1) + (xMax - p1(0)) * slopeM;
                p1 = Point{xMax, y};
            }
            else
            {
                float y = p1(1) + (xMin - p1(0)) * slopeM;
                p1 = Point{xMin, y};
            }

            p1RegionCode = getRegionCode(p1, viewPort);
        }
        else
        {
            if (p2RegionCode >= 8)
            {
                float x = p2(0) + (yMax - p2(1)) / slopeM;
                p2 = Point{x, yMax};
            }
            else if (p2RegionCode >= 4)
            {
                float x = p2(0) + (yMin - p2(1)) / slopeM;
                p2 = Point{x, yMin};
            }
            else if (p2RegionCode >= 2)
            {
                float y = p2(1) + (xMax - p2(0)) * slopeM;
                p2 = Point{xMax, y};
            }
            else
            {
                float y = p2(1) + (xMin - p2(0)) * slopeM;
                p2 = Point{xMin, y};
            }
            p2RegionCode = getRegionCode(p2, viewPort);
        }
    }

    clippedPolygon.push_back(p1);
    clippedPolygon.push_back(p2);
}

void drawViewPort(ViewPort viewPort = VIEW_PORT)
{
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    for (int i = 0; i < 4; i++)
    {
        glVertex2f(viewPort.row(i)(0), viewPort.row(i)(1));
    }
    glEnd();
}

void clipPolygon(Polygon poly, ViewPort viewPort = VIEW_PORT)
{
    for (int i = 0; i < 4; i++)
    {

        // Convert Polygon to Lines
        Line initialLine{
            {poly.row(i)[0], poly.row(i)[1]},
            {poly.row((i + 1) % 4)[0], poly.row((i + 1) % 4)[1]},
        };
        clipLine(initialLine, viewPort);
    }
}

void drawPolygon(Polygon poly, ViewPort viewPort = VIEW_PORT)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < clippedPolygon.size(); i++)
    {
        glVertex2f(clippedPolygon[i](0), clippedPolygon[i](1));
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

    window = glfwCreateWindow(600, 400, "Sutherland Hodgemann Polygon Clipping", nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    clipPolygon(initial, VIEW_PORT);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        drawViewPort();
        drawPolygon(initial);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return -1;
}