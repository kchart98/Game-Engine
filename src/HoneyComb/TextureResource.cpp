#include "TextureResource.h"

TextureResource::~TextureResource()
{


}

void TextureResource::load(std::string path)
{
	int w = 0;
	int h = 0;
	int channels = 0;

	unsigned char *data = stbi_load(path.c_str(), &w, &h, &channels, 4);

	if (!data)
	{
		throw std::exception();
	}

	size.x = w;
	size.y = h;

	glGenTextures(1, &id);

	if (!id)
	{
		throw std::exception();
	}

	glBindTexture(GL_TEXTURE_2D, id);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	free(data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);
}

void TextureResource::setPixel(glm::vec3 value)
{

	

}

void TextureResource::setPixel(glm::vec4 value)
{



}

GLuint TextureResource::getId()
{
	return id;
}
