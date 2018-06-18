#include "SystemManager.h"

namespace engine
{
	bool SystemManager::init()
	{
		for (System* s : m_systems)
		{
			if (!s->init())
				return false;
		}
		return true;
	}

	void SystemManager::update()
	{
		for (System* s : m_systems)
		{
			s->update();
		}
	}

	void SystemManager::draw() const
	{
		for (System* s : m_systems)
		{
			s->draw();
		}
	}

	bool SystemManager::shutdown()
	{
		for (System* s : m_systems)
		{
			if (!s->init())
				return false;
		}
		return true;
	}
}