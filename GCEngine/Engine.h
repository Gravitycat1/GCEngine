#pragma once
#ifndef _ENGINE_H
#define _ENGINE_H



namespace engine
{
	class Engine
	{
		//window we'll be rendering to
		 



	public:
		~Engine ();
		//init the system
		int init();
		//mainloop
		void run();

	private:
		bool initSDL();
		bool closeSDL();
	};

}
#endif // !_ENGINE_H
