#pragma once
#ifndef _LOGGER_H
#define _LOGGER_H

#include "Singleton.h"
#include "EngineTypes.h"

namespace engine
{
	class Logger : public Singleton<Logger>
	{
	private:
		//allows singleton to access protected construtor 
		friend Singleton;

		ELogType m_currentLevel;

	protected:

		Logger(): m_currentLevel() {}
	public:
		

		static void Log(const char* message, ELogType l = ELogType::LT_General);
		static ELogType getCurrentLevel();
		static void setCurrentLevel(ELogType l);

	};
}
#endif // !_LOGGER_H