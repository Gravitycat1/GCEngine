#ifndef _WINDOW
#define _WINDOW

#include "System.h"

//forward declare 
	struct SDL_Window;
	struct SDL_Surface;

namespace engine
{
	

	class Window : public System
	{

		SDL_Window* m_window;
		SDL_Surface* m_surface;

	public:
		
		Window();
		~Window();
		bool init() override;
		void update() override;
		void draw() const override;
		bool shutdown() override;
	};
}
#endif //_WINDOW