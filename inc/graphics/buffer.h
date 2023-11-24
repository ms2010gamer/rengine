#pragma once

#include <vendor/GLAD/glad.h>

// Vertex buffer
typedef struct vertex_buffer
{
    unsigned int id;
    const void* data;
    size_t size;
} vertex_buffer;
vertex_buffer create_vertex_buffer(const void* data, size_t size);

void bind_vertex_buffer(vertex_buffer vbo);
void unbind_vertex_buffer();

// Element buffer
typedef struct element_buffer
{
    unsigned int id;
    const void* data;
    size_t size;
} element_buffer;
element_buffer create_element_buffer(const void* data, size_t size);

void bind_element_buffer(element_buffer ebo);
void unbind_element_buffer();