#ifndef DEF_GAME_H
#define DEF_GAME_H
#include "window.h"
#include "timer.h"
#include "renderer.h"
#include "userEvents.h"

class Game : public EventListener {
public:
	bool Init();
	void Load();
	void Loop();
	void Quit();
private:
	Window _window;
	Timer _timer;
	int _fpsLimit{ 60 };
	Renderer _renderer;

	void Pause();
};

#endif