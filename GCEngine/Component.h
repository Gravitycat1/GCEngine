#pragma once

namespace engine
{
	class Component
	{
	public:
		Component() {};
		virtual ~Component() {};


		virtual bool init() = 0;
		virtual void update() = 0;
		virtual void draw() const = 0;
		virtual bool shutdown() = 0;
	};
}