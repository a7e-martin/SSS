#ifndef DEF_RENDERER_H
#define DEF_RENDERER_H
#include <GL/glew.h>
#include "eventManager.h"

class Window;

class Renderer : public EventListener{
public:
	bool Init();
	bool Stop();
	void RenderWindow(Window& window);
private:

};

#endif