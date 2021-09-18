#include "Window.h"

int CALLBACK WinMain(
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	LPSTR		lpCmdLine,
	int			nCmdShow) 
{
	Window wnd(800, 300, "Donkey Fart Box");


	//message pump
	MSG msg = {0};
	BOOL gResult;
	while ((gResult = GetMessageA(&msg,nullptr,0,0))>0)
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	if (gResult == -1) {
		return -1;
	}
	else
	{
		return msg.wParam;
	}
}