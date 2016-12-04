#include "window.h"
#include "log.h"
#include "inputEventManager.h"
#include "eventManager.h"
#include "gvars.h"

void GLFWErrorCallBack(int error, const char* desc) {
	LOG("GLFW Error code: 0x{:02x}, desc: {}", error, desc);
}

bool Window::Init(u16 width, u16 height, bool fullscreen, int monitor, int antialiasing, bool vsync)
{
	gInputEventManager.AddAction(GLFW_KEY_ESCAPE, KeyAction( [this] {
		SetShouldClose(true);
	} ));
	glfwSetErrorCallback(&GLFWErrorCallBack);
	if(!glfwInit()) 
		return false;
	LOG("Opening {}x{} window({})", width, height, fullscreen);

	glfwWindowHint(GLFW_SAMPLES, antialiasing);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	if (fullscreen)
	{
		int count;
		GLFWmonitor** monitors = glfwGetMonitors(&count);
		const GLFWvidmode* mode = glfwGetVideoMode(monitors[monitor]);

		glfwWindowHint(GLFW_RED_BITS, mode->redBits);
		glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
		glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
		glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);
		glfwWindowHint(GLFW_AUTO_ICONIFY, 0);

		_window = glfwCreateWindow(width, height, "Space Station Sim", monitors[monitor], nullptr);
	}
	else
	{
		_window = glfwCreateWindow(width, height, "Space Station Sim", nullptr, nullptr);
	}

	if (!_window)
	{
		LOG("GLFW Window error!");
		glfwTerminate();
		return false;
	}
	glfwMakeContextCurrent(_window);

	if (vsync) glfwSwapInterval(1);
	
	return true;

	glfwTerminate();
	return true;
}

GLFWwindow * Window::GetWindow() const
{
	return _window;
}

void Window::Quit()
{
	glfwTerminate();
}

void Window::Update()
{
	glfwSwapBuffers(_window);
}

bool Window::ShouldClose() {
	return _shouldClose;
}

void Window::SetShouldClose(bool shouldClose) {
	_shouldClose = shouldClose;
}
