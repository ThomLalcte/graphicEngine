#include "app.h"

int CALLBACK WinMain(
	HINSTANCE	hInstance,
	HINSTANCE	hPrevInstance,
	LPSTR		lpCmdLine,
	int			nCmdShow) 
{
	try
	{
		return App{}.Go();
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