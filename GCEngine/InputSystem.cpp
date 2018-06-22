#include "InputSystem.h"

#include <SDL\SDL.h>

namespace engine
{
	InputSystem::InputSystem():
		m_shouldClose(false),
		System(ESystemType::ST_INPUT)
	{

	}

	InputSystem::~InputSystem()
	{
	}

	bool InputSystem::init()
	{
		return true;
	}

	void InputSystem::update()
	{
		SDL_Event e;

		m_previousKeys = m_keys;

		//getting all the events
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT:
				m_shouldClose = true;
				break;

			case SDL_KEYDOWN:
				m_keys[e.key.keysym.sym] = true;
				break;

			case SDL_KEYUP:
				m_keys[e.key.keysym.sym] = false;
				break;

			default:
				break;
			}

		}
	}

	void InputSystem::draw() const
	{
	}

	bool InputSystem::shutdown()
	{
		return true;
	}

	bool InputSystem::isKey(unsigned __int32 k)
	{
		return m_keys[k];
	}

	bool InputSystem::wasKeyPressed(unsigned __int32 k)
	{
		
		return !m_previousKeys[k] && m_keys[k];
	}

	bool InputSystem::wasKeyReleased(unsigned __int32 k)
	{
		return m_previousKeys[k] && !m_keys[k];
	}

}