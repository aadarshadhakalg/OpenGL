#pragma once

#include <iostream>
#include <string>
#include <ft2build.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <map>
#include <shader.hpp>

struct Character
{
    unsigned int TextureID; // ID handle of the glyph texture
    glm::ivec2 Size;        // Size of glyph
    glm::ivec2 Bearing;     // Offset from baseline to left/top of glyph
    unsigned int Advance;   // Offset to advance to next glyph
};

class DisplayText
{

public:
    FT_Library ft;
    FT_Face face;
    unsigned int VAO, VBO;

    DisplayText();

    // Stores the Character Struct Mapping of each char
    std::map<char, Character> Characters;

    Shader compile_text_shaders(unsigned int SCR_WIDTH = 800, unsigned int SCR_HEIGHT = 600);

    bool initialize_freetype();

    void render_text(Shader &s, std::string text, float x, float y, float scale, glm::vec3 color);
};
