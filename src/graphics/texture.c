#include <graphics/texture.h>

#define STB_IMAGE_IMPLEMENTATION
#include <vendor/stb_image/stb_image.h>

texture create_texture(const char* path)
{
    texture texture;
    glGenTextures(1, &texture.id);
    glBindTexture(GL_TEXTURE_2D, texture.id);

    stbi_set_flip_vertically_on_load(1);

    int width, height, nrChannels;
    unsigned char *data = stbi_load(path, &width, &height, &nrChannels, 0);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("ERROR: Failed to load texture");
    }
    stbi_image_free(data);
}