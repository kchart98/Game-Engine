#include <HoneyComb/HoneyComb.h>
#include <iostream>
#include <memory>

class Player : public Component
{
public:
	void onTick()
	{
		std::cout << "Hello World" << std::endl;
	}
};


int main()
{

	std::shared_ptr<Core> core = std::make_shared<Core>();
	std::shared_ptr<Entity> player = core->addEntity();
	//player->addCompnent<Player>();

	core->start();

	
	return 0;
}