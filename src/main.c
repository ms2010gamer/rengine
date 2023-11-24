#include <core/window.h>

#include <graphics/buffer.h>
#include <graphics/shader.h>
#include <graphics/texture.h>

int main()
{
    Window window = create_window(800, 600, "test");
    initgl();

    // Vertices + Indices
    float vertices[] = {
    // positions          // texture coords
     0.5f,  0.5f, 0.0f,   1.0f, 1.0f,   // top right
     0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   // bottom right
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f,   // bottom left
    -0.5f,  0.5f, 0.0f,   0.0f, 1.0f    // top left 
    };
    unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
    };  

    // Shaders
const char* vsS =
    "attribute vec3 a_Pos;\n"
    "attribute vec2 a_UV;\n"
    "varying vec2 v_UV;\n"
    "void main(){\n"
        "v_UV = a_UV;\n"
        "gl_Position = vec4(a_Pos, 1.0f);\n"
    "}\n";
const char* fsS =
    "varying vec2 v_UV;\n"
    "uniform sampler2D u_Tex;\n"
    "void main(){\n"
        "gl_FragColor = texture2D(u_Tex, v_UV);\n"
    "}\n";

    shader shader = create_shader(vsS, fsS);
    enable_shader(shader);

    // Texture
    texture texture = create_texture("res/face.png");

    // Rectangle
    vertex_buffer vbo = create_vertex_buffer(vertices, sizeof(vertices));
    element_buffer ebo = create_element_buffer(indices, sizeof(indices));

    int posLoc = glGetAttribLocation(shader.prg, "a_Pos");
    glVertexAttribPointer(posLoc, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(posLoc);

    int uvLoc = glGetAttribLocation(shader.prg, "a_UV");
    glVertexAttribPointer(uvLoc, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(uvLoc);

    while (!window_should_close(window))
    {
        clear_window();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);

        update_window(window);
        window_handle_events();
    }

    return 0;
}