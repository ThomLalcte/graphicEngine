#include "Window.h"

int CALLBACK WinMain(
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	LPSTR		lpCmdLine,
	int			nCmdShow) 
{
	try
	{
		Window wnd(800, 300, "Donkey Fart Box");


		//message pump
		MSG msg = { 0 };
		BOOL gResult;
		while ((gResult = GetMessageA(&msg, nullptr, 0, 0)) > 0)
		{
			TranslateMessage(&msg);
			DispatchMessageW(&msg);
			if (wnd.kbd.KeyIsPressed(VK_MENU)) {
				MessageBoxA(nullptr, "GEUUH", "bravo t'a pesé su espace", MB_OK | MB_ICONHAND);
			}
		}

		if (gResult == -1) {
			return -1;
		}

		//wParam here is the value passed to PostQuitMessage
		return msg.wParam;
	}
	catch (const ChiliException& e) {
		MessageBoxA(nullptr, e.what(), e.GetType(), MB_OK | MB_ICONEXCLAMATION);
	}
	catch (const std::exception& e) {
		MessageBoxA(nullptr, e.what(), "Standard Library Exception", MB_OK | MB_ICONEXCLAMATION);
	}
	catch (...) {
		MessageBoxA(nullptr, "I donno mate", "Unknown Exeption type thrown", MB_OK | MB_ICONEXCLAMATION);
	}
	return -1;
}