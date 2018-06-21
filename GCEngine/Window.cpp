#include "Window.h"
#include "Logger.h"

#include <SDL\SDL.h>
#include <GL\glew.h>

namespace engine
{
	Window::Window() : System(ESystemType::ST_WINDOW)
	{

	}

	Window::~Window()
	{

	}

	bool Window::init()
	{

		initSDL();

			m_window = SDL_CreateWindow("GCEngine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

			if (!m_window)
			{
				Logger::Log("Failed to create window", ELogType::LT_Error);
				return false;
			}
			else
			{
				//m_surface = SDL_GetWindowSurface(m_window);
			}

			//GL F
			SDL_GLContext glcontext = SDL_GL_CreateContext(m_window);

			//this is creating a double buffer
			//draw things on the back buffer then preset that to the screen
			//the buffer that was on screen becomes the back buffer
			SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

			

		
		return true;
	}

	void Window::update()
	{
		SDL_GL_SwapWindow (m_window);
	}

	void Window::draw() const
	{

	}

	bool Window::shutdown()
	{
		

		return shutdownSDL();
	}

	bool engine::Window::initSDL()
	{

		// assert() <- us this instead
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		{
			Logger::Log("Failed to init SDL", ELogType::LT_Error);

			return false;
		}


		return true;
	}

	bool engine::Window::shutdownSDL()
	{

		SDL_FreeSurface(m_surface);
		m_surface = nullptr;

		SDL_DestroyWindow(m_window);
		m_window = nullptr;

		SDL_Quit();

		return true;
	}
}