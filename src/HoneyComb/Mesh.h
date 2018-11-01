#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <iostream>

class MeshResource
{
	bool dirty;
	GLuint id;
	//std::vector<Face>;

private:

	virtual ~MeshResource();
	//void addFace(Face& face);
	GLuint getId();

};