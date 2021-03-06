#include "AppDelegate.h"

AppDelegate* AppDelegate::s_delegate = NULL;

AppDelegate::AppDelegate()
{
	AppDelegate::s_delegate = this;
}

AppDelegate::~AppDelegate()
{
	AppDelegate::s_delegate = NULL;
}

void AppDelegate::runMessageLoop()
{
	MSG msg = {};
	while (::GetMessage(&msg, NULL, NULL, NULL) != WM_QUIT)
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
}

LRESULT CALLBACK AppDelegate::WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	LRESULT result = s_delegate->doProc(hWnd, msg, wParam, lParam);
	if (result != -1)
		return result;
	return ::DefWindowProc(hWnd, msg, wParam, lParam);
}