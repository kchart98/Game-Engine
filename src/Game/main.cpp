#include <HoneyComb/HoneyComb.h>
#include <iostream>

class TestScreen : public Component
{
public:
	void onInit(std::string color)
	{
		//std::cout << "onInit " << color << std::endl;
	}

	void onBegin()
	{
		//std::cout << "onBegin" << std::endl;
	}

	void onTick()
	{
		//std::cout << "onTick" << std::endl;
	}

	void onDisplay()
	{
		//std::cout << "onDisplay" << std::endl;
	}

	void onGUI()
	{
		//std::cout << "onGUI" << std::endl;
	}

};


int main()
{
	std::shared_ptr<Core> core = Core::initialize();
	std::shared_ptr<Entity> background = core->addEntity();
	std::shared_ptr<Entity> player = core->addEntity();
	
	std::shared_ptr<TestScreen> ts = background->addComponent<TestScreen>("Test");
	
	std::shared_ptr<MeshResource> model = core->getResources()->load<MeshResource>("../resources/models/curuthers/curuthers.obj");
	std::shared_ptr<TextureResource> tex = core->getResources()->load<TextureResource>("../resources/images/player.png");

	std::shared_ptr<MeshRenderer> modelRenderer = player->addComponent<MeshRenderer>(model);
	modelRenderer->setTexture(tex);
	
	std::shared_ptr<Audio> audio = std::make_shared<Audio>("../resources/audio/dixie_horn.ogg");
	audio->play;

	core->start();
		
	return 0;
}