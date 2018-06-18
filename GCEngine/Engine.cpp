#include "Engine.h"
#include "Logger.h"
#include "SystemManager.h"


#include "SDL\SDL.h"

#include <chrono>
#include <iostream>

engine::Engine::~Engine()
{
	SystemManager::GetInstance().shutdown();
	closeSDL();
}

int engine::Engine::init()
{
	
#if !_DEBUG

	Logger::Log("Initalizing the game.");

#endif

	if(!initSDL())
	{
		return 1;
	}

	if (!SystemManager::GetInstance().init())
		return 2;

	return 0;
}

void engine::Engine::run()
{
	bool quit = false;
	SDL_Event e;

	//infinte engine loop
	while (!quit) 
	{
		const auto start = std::chrono::high_resolution_clock::now();

		//getting all the events
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT:
				quit = true;
				break;

			default:
				break;
			}

		}
		SystemManager::GetInstance().update();
		SystemManager::GetInstance().draw();

		const auto end = std::chrono::high_resolution_clock::now();
		const auto durationMS = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

		std::cout << durationMS.count() << "ms" << std::endl;
	}
}

bool engine::Engine::initSDL()
{

	// assert() <- us this instead
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		Logger::Log("Failed to init SDL", ELogType::LT_Error);

		return false;
	}
	

	return true;
}

bool engine::Engine::closeSDL()
{

	SDL_Quit();

	return true;
}