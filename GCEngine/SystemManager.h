#pragma once

#include "Singleton.h"
#include <algorithm>
#include <vector>

#include "Window.h"

namespace engine
{
	class SystemManager : public Singleton<SystemManager>
	{

		friend Singleton;
		//forward delclaring 
		//so that we don't have to include it in the header file
		std::vector<class System*> m_systems;

	protected:

		SystemManager() 
		{
			m_systems.emplace_back(new Window);
		}

	public:

		bool init();
		void update();
		void draw()const;
		bool shutdown();


		template<class T>
		T* GetSystems() const
		{
			/*System* s = std::find_if(m_systems.begin(), m_systems.end(), [T](System* s)-> bool
			{
				return dynamic_cast<T>(s) != nullptr;
			});*/
			for (System* s : m_systems)
			{
				T* currentSystem = dynamic_cast<T*>(s);
				if (currentSystem)
					return currentSystem;
			}
			return nullptr;
		}

		inline const std::vector<class System*>& GetSystems() const 
		{
			return m_systems;
		}

	};
}