#include <graphics/shader.h>

shader create_shader(const char* vsS, const char* fsS)
{
    shader shader;

    shader.vs = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shader.vs, 1, &vsS, NULL);
    glCompileShader(shader.vs);

    shader.fs = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shader.fs, 1, &fsS, NULL);
    glCompileShader(shader.fs);

    shader.prg = glCreateProgram();
    glAttachShader(shader.prg, shader.vs);
    glAttachShader(shader.prg, shader.fs);
    glLinkProgram(shader.prg);

    return shader;
}

void enable_shader(shader shader)
{
    glUseProgram(shader.prg);
}

void disable_shader()
{
    glUseProgram(0);
}

void delete_shader(shader shader)
{
    glDeleteShader(shader.vs);
    glDeleteShader(shader.fs);
    glDeleteProgram(shader.prg);
}