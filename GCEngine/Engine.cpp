#include "Engine.h"
#include "Logger.h"

#include "SDL\SDL.h"

engine::Engine::~Engine()
{
	closeSDL();
}

int engine::Engine::init()
{
	
#if !_DEBUG

	Logger::Log("Initalizing the game.");

#endif

	initSDL();

	return 0;
}

void engine::Engine::run()
{
}

void engine::Engine::initSDL()
{

	// assert() <- us this instead
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		Logger::Log("Failed to init SDL", ELogType::LT_Error);

		//return;
	}
	else 
	{
		m_window = SDL_CreateWindow("GCEngine", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
		if (!m_window)
		{
			Logger::Log("Failed to create window", ELogType::LT_Error);
		}
		else
		{
			m_surface = SDL_GetWindowSurface(m_window);
		}
	}
}

void engine::Engine::closeSDL()
{
	SDL_FreeSurface(m_surface);
	m_surface = nullptr;

	SDL_DestroyWindow(m_window);
	m_window = nullptr;

	SDL_Quit();
}