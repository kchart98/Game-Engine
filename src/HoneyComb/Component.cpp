#include "Component.h"
#include <iostream>

//void Component::~Component()
//{
//	int test = 0;
//}

void Component::onTick()
{
	std::cout << "Hello World" << std::endl;
}