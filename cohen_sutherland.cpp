#include <iostream>
#include <GLFW/glfw3.h>
#include <Eigen/Dense>
#include <algorithm>

typedef Eigen::Matrix<float, 4, 2> ViewPort;
typedef Eigen::Matrix<float, 2, 2> Line;
typedef Eigen::Matrix<float, 1, 2> Point;

const ViewPort VIEW_PORT{
    {-0.5f, -0.5f},
    {0.5f, -0.5f},
    {0.5f, 0.5f},
    {-0.5f, 0.5f}};

const Line initial{
    {-1.0f, -1.0f},
    {1.0f, 1.0f},
};

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

Line clipLine(Line l1, ViewPort viewPort)
{
    Point p1 = l1.row(0);
    Point p2 = l1.row(1);

    int p1RegionCode = getRegionCode(p1, viewPort);
    int p2RegionCode = getRegionCode(p2, viewPort);

    std::cout << p1RegionCode << std::endl;
    std::cout << p2RegionCode << std::endl;

    float slopeM = (p2(0) - p1(0)) / (p2(1) - p1(1));

    while (p1RegionCode != 0 || p2RegionCode != 0)
    {
        int res = p1RegionCode & p2RegionCode;

        // std::cout << "p1REgion COde: "  << p1RegionCode << std::endl;
        // std::cout << "p2Region Code: "  << p2RegionCode << std::endl;
        // std::cout << "res: "  << res << std::endl;

        if (res != 0)
        {
            std::cout << "The line lies outside viewport" << std::endl;
            exit(1);
        }

        if (p1RegionCode != 0)
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

    return Line{
        {p1(0), p1(1)},
        {p2(0), p2(1)},
    };
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

void drawLine(Line l1, ViewPort viewPort = VIEW_PORT)
{
    Line line = clipLine(l1, viewPort);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_LINES);
    for (int i = 0; i < 2; i++)
    {
        glVertex2f(line.row(i)(0), line.row(i)(1));
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

    window = glfwCreateWindow(600, 400, "Cohen Sutherland", nullptr, nullptr);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        drawViewPort();
        drawLine(initial);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return -1;
}