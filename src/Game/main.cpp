#include <HoneyComb/HoneyComb.h>
#include <iostream>

class TestScreen : public Component
{
public:
	void onInit(std::string color)
	{
		//
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
		
	std::shared_ptr<TestScreen> ts = background->addComponent<TestScreen>("Test");
	
	/*
	std::shared_ptr<Entity> cat = core->addEntity();
	std::shared_ptr<MeshResource> catMesh = core->getResources()->load<MeshResource>("../resources/models/curuthers/curuthers.obj");
	std::shared_ptr<MeshRenderer> modelRenderer = cat->addComponent<MeshRenderer>(catMesh);

	std::shared_ptr<TextureResource> catTex = core->getResources()->load<TextureResource>("../resources/images/curuthers_diffuse.png");
	modelRenderer->setTexture(catTex);
	*/

	std::shared_ptr<Entity> hall = core->addEntity();
	std::shared_ptr<MeshResource> hallMesh = core->getResources()->load<MeshResource>("../resources/models/re_hall/re_house_baked.obj");
	std::shared_ptr<MeshRenderer> modelRenderer = hall->addComponent<MeshRenderer>(hallMesh);

	std::shared_ptr<TextureResource> hallTex = core->getResources()->load<TextureResource>("../resources/images/re_hall_diffuse.png");
	modelRenderer->setTexture(hallTex);


	

	//std::shared_ptr<Audio> audio = std::make_shared<Audio>("../resources/audio/dixie_horn.ogg");
	//audio->play();
	

	core->start();
		
	return 0;
}