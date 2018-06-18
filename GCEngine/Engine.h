#pragma once
#ifndef _ENGINE_H
#define _ENGINE_H

struct SDL_Window;
struct SDL_Surface;

namespace engine
{
	class Engine
	{
		//window we'll be rendering to
		 SDL_Window* m_window;
		 SDL_Surface* m_surface;



	public:
		~Engine ();
		int init();
		void run();

	private:
		void initSDL();
		void closeSDL();
	};

}
#endif // !_ENGINE_H
