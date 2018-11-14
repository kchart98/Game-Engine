#include "Keyboard.h"

bool Keyboard::isKeyDown(double key)
{
	for (std::vector<double>::iterator it = keys.begin(); it != keys.end(); it++)
	{
		if (*it == key)
		{
			return true;
		}
	}

	return false;
}

bool Keyboard::isKeyPressed(double key)
{
	for (std::vector<double>::iterator it = pressedKeys.begin(); it != pressedKeys.end(); it++)
	{
		if (*it == key)
		{
			it = pressedKeys.erase(it);
			return true;
		}
	}

	return false;
}
