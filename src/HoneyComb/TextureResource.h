#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <iostream>
#include <stb_image/stb_image.h>

class TextureResource
{
	GLuint id;
	int type;
	bool dirty;
	glm::vec2 size;

private:

	virtual ~TextureResource();
	void setPixel(glm::vec3 value);
	void setPixel(glm::vec4 value);
	GLuint getId();
	void load(std::string path);

};