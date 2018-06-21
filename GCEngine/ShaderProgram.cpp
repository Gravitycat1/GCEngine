#include "ShaderProgram.h"
#include <iostream>
#include <GL\glew.h>

namespace engine
{
	ShaderProgram::ShaderProgram(const std::string& vertexSource, const std::string& fragmentSource):
		m_vertexSource(vertexSource), m_fragmentSource(fragmentSource)
	{
		
	}

	ShaderProgram::~ShaderProgram()
	{

	}

	bool ShaderProgram::init()
	{
		//start compiling shaders
		int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		const char* vertexShaderSource = m_vertexSource.c_str();
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);

		//checking for compiling errors
		int success;
		char infolog[512];
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infolog);
			std::cout << "Error compiling vertex shader: " << infolog << std::endl;
			return false;
		}

		int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		const char* fragmentShaderSource = m_fragmentSource.c_str();
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);

		//checking for errors when compiling
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infolog);
			std::cout << "Error compiling vertex shader: " << infolog << std::endl;
			return false;
		}

		//creating the program - links the shaders together
		m_id = glCreateProgram();
		//attaching shader
		glAttachShader(m_id, vertexShader);
		glAttachShader(m_id, fragmentShader);
		//we are done attaching shders, now we link them
		glLinkProgram(m_id);
		//cheaking for errors linking the program
		glGetProgramiv(m_id, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(m_id, 512, NULL, infolog);
			std::cout << "Error linking shader program: " << infolog << std::endl;
			return false;
		}

		//clearing up the shader information
		//everything we need is in the program
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);

		return true;
	}

	bool ShaderProgram::shutdown()
	{
		return true;
	}


	void ShaderProgram::use()
	{
		glUseProgram(m_id);
	}

}