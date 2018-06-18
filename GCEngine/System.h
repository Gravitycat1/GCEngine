#pragma once
#include "Singleton.h"

namespace engine
{
	enum class ESystemType : unsigned __int8
	{
		ST_WINDOW,
		ST_INPUT,
		ST_GRAPHICS,
		ST_TOTAL
	};
	class System : public Singleton<System>
	{
		ESystemType m_type;

	public:

		System(ESystemType t) : m_type(t){}

		virtual ~System() {};
		virtual bool init() 
		{ 
			return true;
		}
		virtual void update() {};
		virtual void draw() const {};
		virtual bool shutdown()
		{ 
			return true;
		}

	};
}