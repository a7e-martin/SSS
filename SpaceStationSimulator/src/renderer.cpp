#include "renderer.h"
#include "log.h"
#include "window.h"



bool Renderer::Init()
{
	if (glewInit() != GLEW_OK)
	{
		LOG("Failed to initialize GLEW");
		return false;
	}
	return true;
}

bool Renderer::Stop()
{
	return false;
}

void Renderer::RenderWindow(Window & window)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	window.Update();
}

