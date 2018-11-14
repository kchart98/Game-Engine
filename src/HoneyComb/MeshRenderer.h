#include "Component.h"
#include <memory>

class ShaderProgram;
class TextureResource;
class MeshResource;

class MeshRenderer : public Component
{
	std::weak_ptr<MeshResource> mesh;
	//std::shared_ptr<Material> material;
	void onDisplay();

public:
	void onInit();
	void onInit(std::shared_ptr<MeshResource> model);
	void setMesh(std::weak_ptr<MeshResource>);

	void setTexture(std::weak_ptr<TextureResource>);
	std::weak_ptr<MeshResource> getMesh();

	//getMaterial
	

private:
		
	std::shared_ptr<ShaderProgram> shader;

};