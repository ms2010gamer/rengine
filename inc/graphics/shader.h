#pragma once

#include <vendor/GLAD/glad.h>
#include <stdio.h>

typedef struct shader
{
    unsigned int vs, fs;
    unsigned int prg;
} shader;
shader create_shader(const char* vsS, const char* fsS);

void enable_shader(shader shader);
void disable_shader();
void delete_shader(shader shader);