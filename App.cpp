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
	const float t = timer.Peek();
	std::ostringstream oss;
	oss << "time elapsed: " << std::setprecision(3) << std::fixed << t << "s";
	wnd.SetTitle(oss.str());
}