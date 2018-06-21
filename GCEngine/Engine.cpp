#include "Engine.h"
#include "Logger.h"
#include "SystemManager.h"
#include "ShaderProgram.h"


#include <SDL\SDL.h>
#include <GL\glew.h>

#include <chrono>
#include <iostream>
#include <Windows.h>

//opengl was based on http://learnopengl.com

const char* vertexShaderSource = "#version 330 core\n"
			"layout (location = 0) in vec3 aPos; \n"
			"void main()\n"
			"{\n"
			"  gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);"
			"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
			"out vec4 FragColor; \n"
			"void main()\n"
			"{\n"
			"  FragColor = vec4(0.5f, 0.0f, 0.3f, 1.0);"
			"}\0";

float vertices[] =
{
	0.5f, 0.5f, 0.0f,
	0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	-0.5f, 0.5f, 0.0f
};

unsigned indices[] =
{
	0, 1, 2,
	1, 2, 3
};

engine::ShaderProgram sp(vertexShaderSource, fragmentShaderSource);

unsigned int VAO, VBO, EBO;

engine::Engine::~Engine()
{

	glDeleteVertexArrays(1, &VAO);
	glDeleteVertexArrays(1, &VBO);
	glDeleteVertexArrays(1, &EBO);

	SystemManager::GetInstance().shutdown();
	
}

int engine::Engine::init()
{
	
#if !_DEBUG

	Logger::Log("Initalizing the game.");

#endif

	

	if (!SystemManager::GetInstance().init())
		return 2;

	sp.init();

	//creating the buffer
	glGenVertexArrays(1, &VBO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	return 0;
}

void engine::Engine::run()
{
	bool quit = false;
	SDL_Event e;

	

	//infinte engine loop
	while (!quit) 
	{
		//timing
		{
			// counts how many frames have passed
			static uint64_t frameCounter = 0;
			// count how many seconds have passed
			static double elapsedSeconds = 0.0;

			static std::chrono::high_resolution_clock clock;
			static auto t0 = clock.now();
		
			++frameCounter;
			auto t1 = clock.now();
			auto deltaTime = t1 - t0;
			t0 = t1;

			elapsedSeconds += deltaTime.count() * 1e-9;
			if (elapsedSeconds > 1.0)
			{
				char buffer[500];
				auto fps = frameCounter / elapsedSeconds;
				sprintf_s(buffer, 500, "FPS: %f\n", fps);

				std::cout << buffer << std::endl;

				frameCounter = 0;
				elapsedSeconds = 0.0;
			}
		}
		

		//getting all the events
		while (SDL_PollEvent(&e) != 0)
		{
			switch (e.type)
			{
			case SDL_QUIT:
				quit = true;
				break;

			default:
				break;
			}

		}
		SystemManager::GetInstance().update();
		SystemManager::GetInstance().draw();

		// drawing square
		sp.use();
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		
		
		////todo: remove this when adding a mesh
		//glEnableClientState(GL_COLOR_ARRAY);

		////starts drawing
		//glBegin(GL_TRIANGLES);

		//glColor3b(1.0f, 0.0f, 0.0f);// supose to be red but is black
		//glVertex2f(0, 0);
		//glVertex2f(0, 500);
		//glVertex2f(500, 500);

		////ends drawing
		//glEnd();

	}
}

