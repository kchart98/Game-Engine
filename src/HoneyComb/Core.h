#include <SDL2/SDL.h>

#include <memory>
#include <vector>

class Entity;

class Core
{
public:

	static std::shared_ptr<Core> initialize(); //Initialize window
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();


private:
	std::vector<std::shared_ptr<Entity> > entities;
	std::weak_ptr<Core> self;
	bool running;

	SDL_Window *window;
};