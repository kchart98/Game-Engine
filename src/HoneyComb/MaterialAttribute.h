#include "Resources.h"

#include <string>
#include <iostream>
#include <vector>

class MaterialAttribute
{
	std::string name;
	int type;
	float floatValue;
	std::weak_ptr<TextureResource>;
	
};

