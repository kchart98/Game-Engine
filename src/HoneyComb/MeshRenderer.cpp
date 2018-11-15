#include "MeshRenderer.h"
#include "Resources.h"
#include "Mesh.h"
#include "TextureResource.h"

#include "VertexBuffer.h"
#include "Shaders.h"

#include <glm/ext.hpp>
#include <iostream>

void MeshRenderer::onInit()
{
	shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
}

void MeshRenderer::onInit(std::shared_ptr<MeshResource> mesh)
{
	onInit();
	setMesh(mesh);
}

void MeshRenderer::setMesh(std::weak_ptr<MeshResource> mesh)
{
	this->mesh = mesh;
}

std::weak_ptr<MeshResource> MeshRenderer::getMesh()
{
	return mesh;
}

void MeshRenderer::onDisplay()
{
	//shader->setUniform("in_Projection", glm::perspective(glm::radians(65.0f), (float)1280 / (float)720, 0.1f, 100.f));

	glm::mat4 model(1.0f);
	model = glm::rotate(model, glm::radians(angle), glm::vec3(0, 1, 0));
	shader->setUniform("in_View", glm::inverse(model));	
	
	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f));
	shader->setUniform("in_Model", model);	

	shader->setUniform("in_Projection", glm::mat4(1.0f));

	shader->draw(mesh);
	angle += 0.1f;
}

void MeshRenderer::setTexture(std::weak_ptr<TextureResource> texture)
{
	shader->setUniform("in_Texture", texture);
}