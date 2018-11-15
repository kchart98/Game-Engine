#include "Resource.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <iostream>
#include <stb_image/stb_image.h>

class MeshRenderer;

class TextureResource : public Resource
{
	friend class MeshRenderer;

	GLuint id;
	glm::vec2 size;
	void onLoad(std::string path);
	std::shared_ptr<TextureResource> data;
	glm::vec2 getSize();

	//void onCreate(int width, int height);	

public:

	GLuint getId();
	
};