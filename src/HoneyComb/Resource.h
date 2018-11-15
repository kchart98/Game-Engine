#ifndef RESOURCE_H
#define RESOURCE_H

#include <string>
#include <memory>
#include <GL/glew.h>

class Resources;

class Resource
{
	friend class Resources;

	virtual void onLoad(std::string path);
	void load(std::string path);

	std::string path;

public:
	
	std::string getPath();

};

#endif