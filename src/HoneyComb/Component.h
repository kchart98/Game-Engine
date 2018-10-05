#include <vector>
#include <memory>

#pragma once
#ifdef COMPONENT_H
#endif
#define COMPONENT_H

class Component
{
public:
	//virtual void ~Component();
	virtual void onTick();

	template <typename T>
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		components.push_back(rtn);
		return rtn;
	}

};