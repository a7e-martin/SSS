#include "game.h"
#include "gvars.h"
#include <chrono>
#include <thread>
#include "testEntity.h"
#include "log.h"


bool Game::Init()
{
	if(!_window.Init(800, 600, false, 1, 1, false)) return false;


	return true;
}

void Game::Load()
{

}

void Game::Loop()
{
	_timer.Start();
	_renderer.Init();
    gInputEventManager.Init(&_window);

	TestEntity te;

	gFrame = 0;
	while (!_window.ShouldClose())
	{
		gEventManager.ProcessEvents();
        gInputEventManager.Update();
		gFrame++;
		_renderer.RenderWindow(_window);
		Pause();
	}
	
}

void Game::Quit()
{
}

void Game::Pause()
{
	const double frame = 1 / (double)_fpsLimit;
	double time = _timer.GetTime();

	if (time < frame)
	{
		double sleepTime = frame - time;
		std::chrono::milliseconds duration((int)(sleepTime * 1000));
		std::this_thread::sleep_for(duration);
	}
	_timer.Reset();
}
