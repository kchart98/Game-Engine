#include "Component.h"
#include <memory>

class VertexArray;
class ShaderProgram;
class TextureResource;
class MeshResource;

class MeshRenderer : public Component
{
	//std::weak_ptr<Mesh> mesh;
	//std::shared_ptr<Material> material;

public:
	void onInit();

	void setMesh(std::weak_ptr<MeshResource>);
	void setTexture(std::weak_ptr<TextureResource>);

	//getMesh
	//getMaterial
	

private:
	void onDisplay();
	
	//std::shared_ptr<VertexArray> shape;
	std::shared_ptr<ShaderProgram> shader;

};