#include "Resource.h"
#include <GL/glew.h>

void Resource::onLoad(std::string path)
{
}

void Resource::load(std::string path)
{
	this->path = path;
	onLoad(path);
}

std::string Resource::getPath()
{
	return path;
}