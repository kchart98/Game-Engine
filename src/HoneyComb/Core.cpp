#include "Core.h"
#include "Entity.h"
#include "Resources.h"
#include "Keyboard.h"
#include "Audio.h"

#include <GL/glew.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

std::shared_ptr<Core> Core::initialize() //Initialize window
{

	std::shared_ptr<Core> rtn = std::make_shared<Core>();
	rtn->running = false;
	rtn->self = rtn;
	rtn->resources = std::make_shared<Resources>();
	rtn->keyboard = std::make_shared<Keyboard>();

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	rtn->window = SDL_CreateWindow("HoneyComb",	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(rtn->window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}

	//Initilise Audio
	rtn->device = alcOpenDevice(NULL);

	if (!rtn->device)
	{
		throw std::exception();
	}

	rtn->context = alcCreateContext(rtn->device, NULL);

	if (!rtn->context)
	{
		alcCloseDevice(rtn->device);
		throw std::exception();
	}

	if (!alcMakeContextCurrent(rtn->context))
	{
		alcDestroyContext(rtn->context);
		alcCloseDevice(rtn->device);
		throw std::exception();
	}

	return rtn;
}

void Core::start()
{
	running = true;

	while (running)
	{
		SDL_Event event = { 0 };

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = true;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				double key = event.key.keysym.sym;
				keyboard->keys.push_back(key);
				keyboard->pressedKeys.push_back(key);
			}
			else if (event.type == SDL_KEYUP)
			{
				double key = event.key.keysym.sym;

				for (std::vector<double>::iterator kit = keyboard->keys.begin();
					kit != keyboard->keys.end();)
				{
					if (*kit == key)
					{
						kit = keyboard->keys.erase(kit);
					}
					else
					{
						kit++;
					}
				}
			}
		}

		if (keyboard->isKeyDown(KEY_LEFT))
		{
			std::shared_ptr<Audio> audio = std::make_shared<Audio>("../resources/audio/dixie_horn.ogg");
			audio->play();
		}
			
		
		for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->tick();
		}

		glEnable(GL_CULL_FACE);
		glEnable(GL_DEPTH_TEST);
		glClearColor(1.0f, 0.90f, 0.67f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->display();
		}				

		for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->GUI();
		}

		SDL_GL_SwapWindow(window);	
	}
}

void Core::stop()
{
	running = false;
}

std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
	entities.push_back(rtn);
	rtn->self = rtn;
	rtn->core = self;
	return rtn;
}

std::shared_ptr<Resources> Core::getResources()
{
	return resources;
}


std::shared_ptr<Audio> Core::getAudio()
{
	return audio;
}


std::shared_ptr<Keyboard> Core::getKeyboard()
{
	return keyboard;
}
