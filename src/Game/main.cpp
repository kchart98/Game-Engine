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
	std::shared_ptr<MeshRenderer> triangle = player->addComponent<MeshRenderer>();

	std::shared_ptr<Texture>
	
	core->start();
		
	return 0;
}