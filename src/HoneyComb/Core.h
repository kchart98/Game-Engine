#include <memory>
#include <vector>

class Entity;

class Core
{
private:
	std::vector<std::shared_ptr<Entity> > entities;

public:
	
	void start();
	std::shared_ptr<Entity> addEntity();
	//void stop();
	


};