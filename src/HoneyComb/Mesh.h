#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <iostream>

class Mesh
{
	bool dirty;
	std::vector<Face>;

private:

	virtual ~Mesh();
	void addFace(Face& face);
	GLuint getId();

};