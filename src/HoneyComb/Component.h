#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
#include <memory>
#include "MeshRenderer.h"
#include "Transform.h"

class Entity;
class Core;
class Resources;

class Component
{
	friend class Entity;

public:
	virtual ~Component();
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Resources> getResources();
	std::shared_ptr<Transform> getTransform();

private:
	std::weak_ptr<Entity> entity;
	bool began;

	virtual void onInit();
	virtual void onBegin();
	virtual void onTick();
	virtual void onDisplay();
	virtual void onGUI();
};

#endif