#pragma once

#include <string>
#include "Resource.h"

namespace engine
{
	class ShaderProgram : public Resource
	{
	private:
		std::string m_vertexSource;
		std::string m_fragmentSource;

		int m_id;

	public:

		ShaderProgram(const std::string& vertexSource, const std::string& fragmentSource);
		~ShaderProgram();

		bool init() override;
		bool shutdown() override;
		void use();
	};
}
