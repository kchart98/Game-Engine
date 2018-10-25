#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <iostream>

class TextureResource
{
	GLuint id;
	int type;
	bool dirty;

private:

	virtual ~TextureResource();
	void setPixel(glm::vec3 value);
	void setPixel(glm::vec4 value);
	GLuint getId();

};