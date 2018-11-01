#include <SDL2/SDL.h>

#include <memory>
#include <vector>

class Entity;
class Resources;

class Core
{
public:

	static std::shared_ptr<Core> initialize(); //Initialize window
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();
	std::shared_ptr<Resources> getResources();

private:
	std::vector<std::shared_ptr<Entity> > entities;
	std::shared_ptr<Resources> resources;
	
	std::weak_ptr<Core> self;
	bool running;

	SDL_Window *window;
};