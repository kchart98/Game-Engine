#include "Core.h"

void Core::start()
{
	//bool and changes when not running
	//syop should set this to false

	while (true)
	{
		for (auto it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->tick();
		}

	}

}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
	entities.push_back(rtn);
	return rtn;

}