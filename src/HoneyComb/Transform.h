#include <glm/glm.hpp>
#include <iostream>
#include <vector>

class Transform
{
	glm::vec3 localPositon;
	glm::vec3 localRotation;
	glm::vec3 localScale;

public:

	void translate(glm::vec3 amount);
	void rotate(glm::vec3 amount);
	void scale(glm::vec3 amount);

	void setLocalPosition(glm::vec3 position);
	void setLocalRotation(glm::vec3 rotation);
	void setLocalScale(glm::vec3 scale);

};

