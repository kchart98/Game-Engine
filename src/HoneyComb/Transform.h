#include "Component.h"

#include <iostream>
#include <vector>
#include <glm/ext.hpp>

class Transform : public Component
{
	glm::vec3 localPosition;
	glm::vec3 localRotation;
	glm::vec3 localScale;

public:

	void setLocalPosition(glm::vec3 position);
	void setLocalRotation(glm::vec3 rotation);
	void setLocalScale(glm::vec3 scale);

	glm::vec3 getPosition();
	glm::vec3 getRotation();
	glm::mat4 getModelMatrix();
	
	void translate(glm::vec3 translation);
	void rotate(glm::vec3 rotation);
	void scale(glm::vec3 scale);
};

