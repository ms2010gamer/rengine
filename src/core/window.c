#include "core/window.h"

void window_resize_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

Window create_window(int width, int height, const char* title)
{
    if (!glfwInit())
    {
        printf("ERROR: Failed to initialize GLFW!");
        glfwTerminate();
    }

    Window window;

    window.width = width;
    window.height = height;
    window.title = title;

    window.window = glfwCreateWindow(window.width, window.height, window.title, NULL, NULL);
    glfwSetFramebufferSizeCallback(window.window, window_resize_callback);
    glfwMakeContextCurrent(window.window);

    return window;
}

bool initgl()
{
    if (!gladLoadGLES2Loader((GLADloadproc)glfwGetProcAddress))
    {
        printf("ERROR: Failed to initialize GLAD!");
        return -1;
    }
}

void update_window(Window window)
{
    glfwSwapBuffers(window.window);
}

void clear_window()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void window_handle_events()
{
    glfwPollEvents();
}

bool window_should_close(Window window)
{
    return window.should_close = glfwWindowShouldClose(window.window);
}