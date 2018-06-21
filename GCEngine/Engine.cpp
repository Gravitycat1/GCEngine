#include "Engine.h"
#include "Logger.h"
#include "SystemManager.h"


#include <SDL\SDL.h>
#include <GL\glew.h>

#include <chrono>
#include <iostream>
#include <Windows.h>

engine::Engine::~Engine()
{
	SystemManager::GetInstance().shutdown();
	
}

int engine::Engine::init()
{
	
#if !_DEBUG

	Logger::Log("Initalizing the game.");

#endif

	

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
		//timing
		{
			// counts how many frames have passed
			static uint64_t frameCounter = 0;
			// count how many seconds have passed
			static double elapsedSeconds = 0.0;

			static std::chrono::high_resolution_clock clock;
			static auto t0 = clock.now();
		
			++frameCounter;
			auto t1 = clock.now();
			auto deltaTime = t1 - t0;
			t0 = t1;

			elapsedSeconds += deltaTime.count() * 1e-9;
			if (elapsedSeconds > 1.0)
			{
				char buffer[500];
				auto fps = frameCounter / elapsedSeconds;
				sprintf_s(buffer, 500, "FPS: %f\n", fps);

				std::cout << buffer << std::endl;

				frameCounter = 0;
				elapsedSeconds = 0.0;
			}
		}
		

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

		
		
		//todo: remove this when adding a mesh
		glEnableClientState( GL_COLOR_ARRAY);

		//starts drawing
		glBegin(GL_TRIANGLES);

		glColor3b(1.0f, 0.0f, 0.0f);
		glVertex2f(0, 0);
		glVertex2f(0, 500);
		glVertex2f(500, 500);

		//ends drawing
		glEnd();

	}
}

