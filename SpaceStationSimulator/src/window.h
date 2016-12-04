#ifndef DEF_WINDOW_H
#define DEF_WINDOW_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "eventManager.h"
#include "types.h"

class Window {
public:
	bool Init(u16 width, u16 height, bool fullscreen, int monitor, int antialiasing, bool vsync);
	GLFWwindow* GetWindow() const;
	void Quit();
	void Update();
    bool ShouldClose();
    void SetShouldClose(bool shouldClose);

private:
	GLFWwindow *_window;
	bool _shouldClose{false};
};
#endif