#include "Resources.h"

#include <string>
#include <iostream>
#include <vector>
class MaterialAttribute;

class Material
{
	std::weak_ptr<ShaderProgram> shader;
	std::vector<MaterialAttribute> attributes;

public:

	void setShader(shader);
	void setValue(std::string name; std::weak_ptr<TextureResource> value);
	void setValue(std::string name; float value);
	std::shared_ptr<ShaderProgram> getShader();
	
};

