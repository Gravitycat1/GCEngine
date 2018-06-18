#include "Engine.h"
#include "Logger.h"

int engine::Engine::init()
{
	
#if !_DEBUG

	Logger::Log("Initalizing the game.");

#endif

	return 0;
}

void engine::Engine::run()
{
}
