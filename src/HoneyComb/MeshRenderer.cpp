#include "MeshRenderer.h"
#include "Resources.h"
#include "Mesh.h"
#include "TextureResource.h"

#include "VertexBuffer.h"
#include "Shaders.h"

#include <iostream>

void MeshRenderer::onInit()
{
	/*
	std::shared_ptr<VertexBuffer> positions = std::make_shared<VertexBuffer>();
	positions->add(glm::vec3(0.0f, 0.5f, 0.0f));
	positions->add(glm::vec3(-0.5f, -0.5f, 0.0f));
	positions->add(glm::vec3(0.5f, -0.5f, 0.0f));

	std::shared_ptr<VertexBuffer> colors = std::make_shared<VertexBuffer>();
	colors->add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
	colors->add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	colors->add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));

	std::shared_ptr<VertexBuffer> texCoords = std::make_shared<VertexBuffer>();
	texCoords->add(glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));
	texCoords->add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));
	texCoords->add(glm::vec4(1.0f, 0.0f, 0.0f, 1.0f));

	//shape->setBuffer("in_Color", colors);

	shader = std::make_shared<ShaderProgram>("../resources/shaders/simple.vert", "../resources/shaders/simple.frag");
	*/
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
	shader->setUniform("in_Model", glm::mat4(1.0f));
	shader->setUniform("in_Projection", glm::mat4(1.0f));
}

void MeshRenderer::setTexture(std::weak_ptr<TextureResource> texture)
{
	shader->setUniform("in_Texture", texture);
}