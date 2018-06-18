#include "Logger.h"
#include <iostream>

namespace engine
{
	void Logger::Log(const char * message, ELogType l /*= ELogType::LT_General*/)
	{
		if(l>= Logger::GetInstance().m_currentLevel)
		std::cout << message << std::endl;
	}
	ELogType Logger::getCurrentLevel()
	{
		return Logger::GetInstance().m_currentLevel;
	}
	void Logger::setCurrentLevel(ELogType l = ELogType::LT_General)
	{
		Logger::GetInstance().m_currentLevel = l;
	}
}