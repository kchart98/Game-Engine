#include "Component.h"
#include <memory>


class VertexArray;
class ShaderProgram;

class MeshRenderer : public Component
{
public:
	void onInit();

private:
	void onDisplay();

	std::shared_ptr<VertexArray> shape;
	std::shared_ptr<ShaderProgram> shader;

};