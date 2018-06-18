#include "Window.h"
#include <SDL\SDL.h>
#include "Logger.h"

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
		
			m_window = SDL_CreateWindow("GCEngine", 100, 100, 800, 600, SDL_WINDOW_SHOWN);
			if (!m_window)
			{
				Logger::Log("Failed to create window", ELogType::LT_Error);
				return false;
			}
			else
			{
				m_surface = SDL_GetWindowSurface(m_window);
			}
		
		return true;
	}

	void Window::update()
	{
		SDL_UpdateWindowSurface(m_window);
	}

	void Window::draw() const
	{

	}

	bool Window::shutdown()
	{
		SDL_FreeSurface(m_surface);
		m_surface = nullptr;

		SDL_DestroyWindow(m_window);
		m_window = nullptr;

		return true;
	}
}