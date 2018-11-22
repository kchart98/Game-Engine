#include "Transform.h"

void Transform::setLocalPosition(glm::vec3 position)
{
	this->localPosition = position;
}

void Transform::setLocalRotation(glm::vec3 rotation)
{
	this->localRotation = rotation;
}

void Transform::setLocalScale(glm::vec3 scale)
{
	this->localScale = scale;
}


glm::vec3 Transform::getPosition()
{
	return localPosition;
}

glm::vec3 Transform::getRotation()
{
	return localRotation;
}

glm::mat4 Transform::getModelMatrix()
{
	glm::mat4 rtn = glm::mat4(1.0);
	/*
	rtn = rtn * qsoft::Matrix::translation(position);
	rtn = rtn * qsoft::Matrix::rotation(rotation);
	rtn = rtn * qsoft::Matrix::scale(scale);
	*/
	return rtn;
}

void Transform::translate(glm::vec3 translation)
{
	//glm::vec4 fwd = glm::rotate(localRotation) * glm::vec4(translation, 1);
	//localPosition = localPosition + glm::vec3(fwd);
}

void Transform::rotate(glm::vec3 rotation)
{
	float a = atan2(this->localPosition.z - rotation.z, this->localPosition.x - rotation.x);
	localRotation.y = 90 + a * 180.0f / 3.14f;
}

