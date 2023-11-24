#pragma once

#include <vendor/GLAD/glad.h>
#include <vendor/GLFW/glfw3.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Window
{
    GLFWwindow* window;
    const char* title;
    int width, height;
    bool should_close;
} Window;
Window create_window(int width, int height, const char* title);
bool initgl();

void update_window(Window window);
void clear_window();
void window_handle_events();
bool window_should_close(Window window);