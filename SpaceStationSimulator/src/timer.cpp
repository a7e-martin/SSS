#include "timer.h"

#include <GLFW/glfw3.h>

void Timer::Reset()
{
	_startTime = glfwGetTime();
}

void Timer::Start()
{
	_startTime = glfwGetTime();
}

double Timer::GetTime()
{
	return glfwGetTime() - _startTime;
}
