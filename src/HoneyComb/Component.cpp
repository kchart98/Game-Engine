#include "Component.h"
#include "Entity.h"
#include <iostream>

void Component::onInit() { }
void Component::onBegin() { }
void Component::onTick(){ }
void Component::onDisplay() { }
void Component::onGui() { }

std::shared_ptr<Entity> Component::getEntity()
{
	return entity.lock();
}

std::shared_ptr<Core> Component::getCore()
{
	return getEntity()->getCore();
}