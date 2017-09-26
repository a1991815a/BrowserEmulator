#ifndef __APPDELEGATE_H__
#define __APPDELEGATE_H__
#include <windows.h>
#include <tchar.h>
#include "CefMixedMessageLoop.h"

typedef struct {
	WNDCLASSEX wndClassEx;
	const TCHAR* wndName;
	WNDPROC winProc;
	DWORD dwStyle;
	int x, y, cx, cy;
	HWND hParent;
	HMENU hMenu;
	LPVOID lpParam;
} WindowInfo;

class AppDelegate : public CefMixedMessageLoop
{
public:
	AppDelegate();
	~AppDelegate();
	virtual HWND createWindow(WindowInfo* windowInfo) const = 0;
	virtual bool destroyWindow(HWND window) const = 0;
	virtual void runMessageLoop();
	virtual int doProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) = 0;

	static LRESULT CALLBACK WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
	static AppDelegate* s_delegate;
};
#endif
