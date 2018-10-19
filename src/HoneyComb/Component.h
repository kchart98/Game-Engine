#ifndef COMPONENT_H
#define COMPONENT_H

#include <vector>
#include <memory>

class Entity;
class Core;

class Component
{
	friend class Entity;

public:
	virtual ~Component();
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Entity> getEntity();

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