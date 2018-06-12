#include "Logger.h"
#include <iostream>

namespace engine
{
	void Logger::Log(const char * message, ELogType l /*= ELogType::LT_Everything*/)
	{
		std::cout << message << std::endl;
	}
	ELogType Logger::getCurrentLevel() const
	{
		return m_currentLevel;
	}
	void Logger::setCurrentLevel(ELogType l)
	{
		m_currentLevel = l;
	}
}