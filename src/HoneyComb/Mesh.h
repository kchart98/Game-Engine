#include "Resource.h"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <fstream>
#include <iostream>

class VertexBuffer;
class MeshRenderer;
class TextureResource;

class MeshResource : public Resource
{
	friend class MeshRenderer;

	GLuint id;
	bool dirty;
	std::vector<VertexBuffer *> buffers;
	
	void splitStringWhitespace(std::string& input, std::vector<std::string>& output);
	void splitString(std::string& input, char splitter, std::vector<std::string>& output);
	
public:
		
	void onLoad(std::string path);
	void setBuffer(std::string attribute, VertexBuffer *buffer);
	int getVertexCount();
	GLuint getId();

};