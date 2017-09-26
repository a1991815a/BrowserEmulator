#include "WinAppDelegate.h"
#include "include\cef_app.h"

#define TIMER_ID 0x0080

WinAppDelegate::WinAppDelegate(bool multiThreadMsgLoop /*= false*/, int loopTime /*= 500*/)
	: m_browserCount(0), m_loopTime(loopTime), m_multiThreadMsgLoop(m_multiThreadMsgLoop)
{

}

HWND WinAppDelegate::createWindow(WindowInfo* windowInfo /* = NULL*/) const
{
	if (windowInfo == NULL)
	{
		windowInfo = new WindowInfo();
		memset(windowInfo, 0, sizeof(WindowInfo));
		windowInfo->x = windowInfo->y = 0;
		windowInfo->cx = 800;
		windowInfo->cy = 600;
		windowInfo->winProc = WinAppDelegate::WinProc;
		windowInfo->wndName = _T("ä¯ÀÀÆ÷");
		windowInfo->wndClassEx = WNDCLASSEX();
		windowInfo->dwStyle = WS_SIZEBOX | WS_SYSMENU | WS_VISIBLE;
		WNDCLASSEX& wnd_class = windowInfo->wndClassEx;
		wnd_class.cbSize = sizeof(wnd_class);
		wnd_class.hCursor = ::LoadCursor(::GetModuleHandle(NULL), IDC_ARROW);
		wnd_class.hIcon = ::LoadIcon(::GetModuleHandle(NULL), IDI_WINLOGO);
		wnd_class.hIconSm = ::LoadIcon(::GetModuleHandle(NULL), IDI_WINLOGO);
		wnd_class.lpszClassName = _T("master");
		wnd_class.hbrBackground = (HBRUSH)::GetStockObject(WHITE_BRUSH);
		wnd_class.style = CS_HREDRAW | CS_VREDRAW;
		wnd_class.hInstance = m_hInstance;
		wnd_class.lpfnWndProc = WinAppDelegate::WinProc;
	}
	
	WNDCLASSEX wnd_class = windowInfo->wndClassEx;
	::RegisterClassEx(&wnd_class);

	HWND hWnd = ::CreateWindowEx(
		WS_EX_TOPMOST,
		wnd_class.lpszClassName,
		windowInfo->wndName,
		windowInfo->dwStyle,
		windowInfo->x, windowInfo->y,
		windowInfo->cx, windowInfo->cy,
		windowInfo->hParent,
		windowInfo->hMenu,
		m_hInstance,
		windowInfo->lpParam
	);
	::UnregisterClass(wnd_class.lpszClassName, m_hInstance);
	if (CefString(wnd_class.lpszClassName) == _T("master"))
		delete windowInfo;

	::ShowWindow(hWnd, SW_SHOW);

	return hWnd;
}

bool WinAppDelegate::destroyWindow(HWND window) const
{
	return ::DestroyWindow(window) == S_OK;
}

int WinAppDelegate::doProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	char text[32] = {};
	sprintf_s(text, "msg: 0x%X\n", msg);
	OutputDebugStringA(text);
	switch (msg)
	{
	case WM_DESTROY:
		if (--this->m_browserCount == 0)
			CefQuitMessageLoop();
		break;
	case WM_CREATE:
		++this->m_browserCount;
		break;
	case WM_TIMER:
		if(!m_multiThreadMsgLoop)
			::CefDoMessageLoopWork();
		break;
	default:
		return -1;
	}

	return 0;
}

void WinAppDelegate::runMessageLoop()
{
	if(!m_multiThreadMsgLoop)
		::SetTimer(NULL, TIMER_ID, this->m_loopTime, NULL);
	MSG msg = {};
	while (::GetMessage(&msg, NULL, NULL, NULL) != 0)
	{
		::TranslateMessage(&msg);
		::DispatchMessage(&msg);
	}
	if(!m_multiThreadMsgLoop)
		::KillTimer(NULL, TIMER_ID);
}

HWND WinAppDelegate::createMessageWindow()
{
	WNDCLASSEX wc = {};
	wc.cbSize = sizeof(wc);
	wc.lpfnWndProc = DefWindowProc;
	wc.hInstance = m_hInstance;
	wc.lpszClassName = _T("ClientMessageWindow");
	RegisterClassEx(&wc);
	return ::CreateWindow(_T("ClientMessageWindow"), 0, 0, 0, 0, 0, 0, HWND_MESSAGE, 0, m_hInstance, 0);
}
