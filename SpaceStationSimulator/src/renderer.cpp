#include "renderer.h"
#include "log.h"
#include "window.h"
#include "glProgram.h"

GLfloat Renderer::vertexBufferData[] = {
	-1.0f, -1.0f, 0.0f, //1st triangle
	1.0f, -1.0f, 0.0f,
	1.0f, 1.0f, 0.0f, //end of 1st triangle
	-1.0f, 1.0f, 0.0f, //2nd triangle
	-1.0f, -1.0f, 0.0f,
	1.0f, 1.0f, 0.0f //end of 2nd triangle
};

bool Renderer::Init()
{
	if (glewInit() != GLEW_OK)
	{
		LOG("Failed to initialize GLEW");
		return false;
	}

	//Load the square in the buffer
	
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexBufferData), vertexBufferData, GL_STATIC_DRAW);

	GlProgram("vertex.vert", "fragment.frag");

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

void Renderer::Render(RendererComponent & rendererComponent)
{
	
}

