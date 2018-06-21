#include "Graphics.h"

#include "Logger.h"

#include <GL\glew.h>



namespace engine
{
	Graphics::Graphics() 
		: System(ESystemType::ST_GRAPHICS)
	{
		//empty
	}

	Graphics::~Graphics()
	{
		//empty
	}

	bool Graphics::init()
	{

		return initOpenGL();
	}

	void Graphics::update()
	{
		
	}

	void Graphics::draw() const
	{
		//GL
		glClearDepth(1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	bool Graphics::shutdown()
	{

		return true;
	}

	inline bool Graphics::initOpenGL()
	{
		GLenum error = glewInit();

		if (error != GLEW_OK)
		{
			Logger::Log("failed to init glew", ELogType::LT_Error);
			return false;
		}

		//backdrop color, blueish
		glClearColor(0.2f, 0.3f, 0.7f, 1.0f);

		return true;
	}

	bool Graphics::shutdownOpenGL()
	{
		return true;
	}
}