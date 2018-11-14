#include "Core.h"
#include "Entity.h"

#include <GL/glew.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

std::shared_ptr<Core> Core::initialize() //Initialize window
{

	std::shared_ptr<Core> rtn = std::make_shared<Core>();
	rtn->running = false;
	rtn->self = rtn;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	rtn->window = SDL_CreateWindow("HoneyComb",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

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
				running = false;
			}
		}
		
		
		for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->tick();
		}

		glClearColor(1.0f, 0.90f, 0.67f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_TEST);

		for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->display();
		}
				
		//glDisable (GL_DEPTH_TEST);
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
