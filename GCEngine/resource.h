#pragma once

namespace engine
{
	class Resource
	{
	public:
		Resource() {};
		~Resource() {};

		virtual bool init() = 0;
		virtual bool shutdown() = 0;
	};
}
