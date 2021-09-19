#include "App.h"
#include <sstream>
#include <iomanip>

App::App() 
	:
	wnd(800, 300, "Donkey Fart Box")
{}

int App::Go()
{
	while (true)
	{
		if (const auto ecode = Window::ProcessMessages()) {
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame() 
{
	const float c = sin(timer.Peek()) / 2.0f + 0.5f;
	wnd.Gfx().clearBuffer(c,1-c,1.0f);
	wnd.Gfx().EndFrame();
}