#pragma once

#include "System.h"

namespace engine
{

	class Graphics : public System
	{


	public:

		Graphics();
		~Graphics();

		bool init() override;
		void update() override;
		void draw() const override;
		bool shutdown() override;

		bool initOpenGL();
		bool shutdownOpenGL();

	};
}