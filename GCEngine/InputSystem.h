#pragma once
#include "System.h"

#include <map>

#include <SDL\SDL.h>

namespace engine
{
	class InputSystem : public System
	{
		bool m_shouldClose;

		std::map<unsigned __int32, bool> m_keys;
		std::map<unsigned __int32, bool> m_previousKeys;

	public:
		InputSystem();
		~InputSystem();

		bool init() override;
		void update() override;
		void draw() const override;
		bool shutdown() override;

		bool isKey(unsigned __int32 k);
		bool wasKeyPressed(unsigned __int32 k);
		bool wasKeyReleased(unsigned __int32 k);


		inline bool wasCloseRequested() const { return m_shouldClose; }
	};
}