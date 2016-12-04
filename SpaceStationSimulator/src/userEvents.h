#ifndef DEF_USEREVENTS_H
#define DEF_USEREVENTS_H
#include "window.h"


class UserEvents {
public:
	bool Init(Window * window);
	void Update();
	void SetWindow(Window* window);

private:
	void SetCallbacks();
	Window* _window;
};

#endif