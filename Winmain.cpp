#include <Windows.h>
#include <sstream>
#include <string>

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(1248);
		break;
	case WM_KEYDOWN:
		if (wParam == 70) {
			SetWindowTextW(hWnd, L"cringe ass unicode");
		}
		break;
	case WM_KEYUP:
		if (wParam == 70) {
			SetWindowTextW(hWnd, L"cringe ass wParam");
		}
		break;
	case WM_CHAR: 
	{
		static std::string title;
		title.push_back((char)wParam);
		SetWindowTextA(hWnd, title.c_str());
	}
		break;
	case WM_LBUTTONDOWN: 
	{
		POINTS pt = MAKEPOINTS(lParam);
		std::ostringstream oss;
		oss << pt.x;
		SetWindowTextA(hWnd, oss.str().c_str());
	}
		break;
	}

	return DefWindowProc(hWnd,msg,wParam,lParam);
}

int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow) 
{
	const auto pClassName = L"hw3dbutts";
	//register window class
	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(wc);			//taille de la structure
	wc.style = CS_OWNDC;			//style (comportement) de la window
	wc.lpfnWndProc = WndProc;		//pointeur vers fonction qui handle les messages
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hCursor = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx(&wc);

	//create window
	HWND hWnd = CreateWindowExW(
		0, pClassName,
		L"Donkey fart box",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU | WS_VSCROLL | WS_SIZEBOX,
		200, 200, 640, 480,
		nullptr, nullptr, hInstance, nullptr
	);

	ShowWindow(hWnd, SW_SHOW);

	//message pump
	MSG msg = {0};
	BOOL gResult;
	while (gResult = GetMessage(&msg,nullptr,0,0)>0)
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