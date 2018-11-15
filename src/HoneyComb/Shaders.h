#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>

class MeshResource;
class TextureResource;

struct Sampler
{
	GLint id;
	std::weak_ptr<TextureResource> texture;
};

class ShaderProgram
{
	GLuint id;
	std::vector<Sampler> samplers;

public:
	ShaderProgram(std::string vert, std::string frag);
	void draw(std::weak_ptr<MeshResource> mesh);

	void setUniform(std::string uniform, glm::vec4 value);
	void setUniform(std::string uniform, float value);
	void setUniform(std::string uniform, int value);

	void setUniform(std::string uniform, glm::mat4 value);
	void setUniform(std::string uniform, std::weak_ptr<TextureResource> texture);

	GLuint getId();

};
