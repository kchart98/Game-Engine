#include "Component.h"
#include <memory>

class VertexArray;
class ShaderProgram;

class MeshRenderer : public Component
{
	//std::weak_ptr<Mesh> mesh;
	//std::shared_ptr<Material> material;

public:
	void onInit();

	//void setMesh();

	//getMesh
	//getMaterial
	

private:
	void onDisplay();
	
	//std::shared_ptr<VertexArray> shape;
	//std::shared_ptr<ShaderProgram> shader;

};