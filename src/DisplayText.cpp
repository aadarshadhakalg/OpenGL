#include <GL/glew.h>


#include <ft2build.h>
#include FT_FREETYPE_H
#include "DisplayText.hpp"

#include <Shader.hpp>


// Define the static Singleton pointer
DisplayText* DisplayText::inst_ = nullptr;

DisplayText* DisplayText::getInstance() {
    if (inst_ == nullptr) {
        inst_ = new DisplayText();
    }
    return(inst_);
}

int DisplayText::init_resources() {
    /* Initialize the FreeType2 library */
    if (FT_Init_FreeType(&ft)) {
        fprintf(stderr, "Could not init freetype library\n");
        return 0;
    }

    /* Load a font */
    if (FT_New_Face(ft, fontfilename, 0, &face)) {
        fprintf(stderr, "Could not open font %s\n", fontfilename);
        return 0;
    }

    program = create_program("../shaders/text.v.glsl", "../shaders/text.f.glsl");
    if(program == 0)
        return 0;

    attribute_coord = get_attrib(program, "coord");
    uniform_tex = get_uniform(program, "tex");
    uniform_color = get_uniform(program, "color");

    if(attribute_coord == -1 || uniform_tex == -1 || uniform_color == -1)
        return 0;

    // Create the vertex buffer object
    glGenBuffers(1, &vbo);

    return 1;
}

/**
 * Render text using the currently loaded font and currently set font size.
 * Rendering starts at coordinates (x, y), z is always 0.
 * The pixel coordinates that the FreeType2 library uses are scaled by (sx, sy).
 */

void DisplayText::render_text(const char *text, float x, float y,  float color[],int font_size=48,float sx = 0.0f, float sy=0.0f) {
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);
    sx = 2.0f / mode->width;
    sy = 2.0f / mode->height;

    glUseProgram(program);
    /* Set font size to 48 pixels, color to black */
    FT_Set_Pixel_Sizes(face, 0, font_size);
    glUniform4fv(uniform_color, 1, color);

    const char *p;
    FT_GlyphSlot g = face->glyph;

    /* Create a texture that will be used to hold one "glyph" */
    GLuint tex;

    glActiveTexture(GL_TEXTURE0);
    glGenTextures(1, &tex);
    glBindTexture(GL_TEXTURE_2D, tex);
    glUniform1i(uniform_tex, 0);

    /* We require 1 byte alignment when uploading texture data */
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    /* Clamping to edges is important to prevent artifacts when scaling */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    /* Linear filtering usually looks best for text */
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    /* Set up the VBO for our vertex data */
    glEnableVertexAttribArray(attribute_coord);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glVertexAttribPointer(attribute_coord, 4, GL_FLOAT, GL_FALSE, 0, 0);

    /* Loop through all characters */
    for (p = text; *p; p++) {
        /* Try to load and render the character */
        if (FT_Load_Char(face, *p, FT_LOAD_RENDER))
            continue;

        /* Upload the "bitmap", which contains an 8-bit grayscale image, as an alpha texture */
        glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, g->bitmap.width, g->bitmap.rows, 0, GL_ALPHA, GL_UNSIGNED_BYTE, g->bitmap.buffer);

        /* Calculate the vertex and texture coordinates */
        float x2 = x + g->bitmap_left * sx;
        float y2 = -y - g->bitmap_top * sy;
        float w = g->bitmap.width * sx;
        float h = g->bitmap.rows * sy;

        point box[4] = {
                {x2, -y2, 0, 0},
                {x2 + w, -y2, 1, 0},
                {x2, -y2 - h, 0, 1},
                {x2 + w, -y2 - h, 1, 1},
        };

        /* Draw the character on the screen */
        glBufferData(GL_ARRAY_BUFFER, sizeof box, box, GL_DYNAMIC_DRAW);
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

        /* Advance the cursor to the start of the next character */
        x += (g->advance.x >> 6) * sx;
        y += (g->advance.y >> 6) * sy;
    }

    glDisableVertexAttribArray(attribute_coord);
    glDeleteTextures(1, &tex);
}

void DisplayText::free_resources() {
    glDeleteProgram(program);
}