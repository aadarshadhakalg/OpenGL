#ifndef FLAG_DISPLAY_TEXT_HPP
#define FLAG_DISPLAY_TEXT_HPP



#include <iostream>
#include <string>
#include <ft2build.h>
#include <freetype/freetype.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <map>
#include <Shader.hpp>
#include <GLFW/glfw3.h>

struct point {
    GLfloat x;
    GLfloat y;
    GLfloat s;
    GLfloat t;
};

class DisplayText
{

public:
    FT_Library ft{};
    FT_Face face{};
    GLuint program{};
    GLint attribute_coord{};
    GLint uniform_tex{};
    GLint uniform_color{};
    GLuint vbo{};

    const char *fontfilename;

    static DisplayText* getInstance();


    int init_resources();

    void render_text(const char *text, float x, float y,  float color[] ,int font_size, float sx, float sy);

    void free_resources();

private:
    static DisplayText* inst_;   // The one, single instance
    DisplayText(){
        fontfilename = "../fonts/Mistral.ttf";
    }
    DisplayText(const DisplayText&);
    DisplayText& operator=(const DisplayText&);
};


#endif