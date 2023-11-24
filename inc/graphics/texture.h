#pragma once

#include <vendor/GLAD/glad.h>

typedef struct texture
{
    unsigned int id;
} texture;
texture create_texture(const char* path);