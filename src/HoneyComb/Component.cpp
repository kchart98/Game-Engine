#include "Component.h"
#include "Entity.h"
#include <iostream>

Component::~Component()
{
}

void Component::onTick()
{
	std::cout << "Hello World" << std::endl;
}

void Component::onInit() 
{



}

void Component::onBegin()
{
}

void Component::onDisplay()
{
}

void Component::onGUI()
{
}


std::shared_ptr<Entity> Component::getEntity()
{
	return entity.lock();
}

std::shared_ptr<Core> Component::getCore()
{
	return getEntity()->getCore();
}