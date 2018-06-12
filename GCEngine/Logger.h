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
		friend Singleton;

		ELogType m_currentLevel;

	protected:

		Logger(): m_currentLevel(ELogType::LT_Everything) {}
	public:
		

		static void Log(const char* message, ELogType l = ELogType::LT_Everything);
		ELogType getCurrentLevel() const;
		void setCurrentLevel(ELogType l);

	};
}
#endif // !_LOGGER_H