#include "SystemManager.h"

namespace engine
{
	SystemManager::SystemManager()
	{
		m_systems.emplace_back(new Window);
		m_systems.emplace_back(new Graphics);

		
	}

	SystemManager::~SystemManager()
	{
		for (System* s : m_systems)
		{
			delete s;
			s = nullptr;
		}

		m_systems.clear();
	}

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