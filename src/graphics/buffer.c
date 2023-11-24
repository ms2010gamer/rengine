#include <graphics/buffer.h>

// Vertex buffer
vertex_buffer create_vertex_buffer(const void* data, size_t size)
{
    vertex_buffer vbo;

    glGenBuffers(1, &vbo.id);
    glBindBuffer(GL_ARRAY_BUFFER, vbo.id);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void bind_vertex_buffer(vertex_buffer vbo)
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo.id);
}

void unbind_vertex_buffer()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

// Element buffer
element_buffer create_element_buffer(const void* data, size_t size)
{
    element_buffer ebo;

    glGenBuffers(1, &ebo.id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo.id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void bind_element_buffer(element_buffer ebo)
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo.id);
}

void unbind_element_buffer()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}