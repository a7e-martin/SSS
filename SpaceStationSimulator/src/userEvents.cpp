#include "userEvents.h"
#include "log.h"
#include <GLFW/glfw3.h>

void MouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
	LOG("Event : MouseButton");
}

bool UserEvents::Init(Window * window)
{
	_window = window;
	SetCallbacks();
	return true;
}

void UserEvents::Update()
{
	glfwPollEvents();
}

void UserEvents::SetWindow(Window * window)
{
	_window = window;
	SetCallbacks();
}


void UserEvents::SetCallbacks()
{
	glfwSetMouseButtonCallback(_window->GetWindow(), MouseButtonCallback);
}

