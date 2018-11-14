#include <SDL2/SDL.h>

#include <AL/al.h>
#include <AL/alc.h>

#include <memory>
#include <vector>

class Entity;
class Resources;
class Keyboard;
class Audio;


class Core
{
public:

	static std::shared_ptr<Core> initialize(); //Initialize window
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();
	std::shared_ptr<Resources> getResources();
	std::shared_ptr<Audio> getAudio();
	std::shared_ptr<Keyboard> getKeyboard();

	template <typename T>
	std::shared_ptr<Entity> getEntity()
	{
		for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin(); it != entities.end(); it++)
		{
			if (!(*it)->alive) continue;

			if ((*it)->hasComponent<T>())
			{
				return *it;
			}
		}

		throw std::exception();
	}
	
private:
	std::vector<std::shared_ptr<Entity> > entities;
	
	std::shared_ptr<Resources> resources;
	std::shared_ptr<Keyboard> keyboard;
	std::shared_ptr<Audio> audio;
	std::weak_ptr<Core> self;

	bool running;
	
	SDL_Window *window;
	ALCdevice* device;
	ALCcontext* context;
};