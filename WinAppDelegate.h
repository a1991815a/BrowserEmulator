#ifndef __WINAPPDELEGATE_H__
#define __WINAPPDELEGATE_H__
#include "AppDelegate.h"


class WinAppDelegate : public AppDelegate
{
public:
	WinAppDelegate(bool multiThreadMsgLoop = false, int loopTime = 500);
	virtual HWND createWindow(WindowInfo* windowInfo = NULL) const override;

	virtual bool destroyWindow(HWND window) const override;

	virtual int doProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) override;

	virtual void runMessageLoop() override;



	HINSTANCE getInstance() const { return m_hInstance; }
	void setInstance(HINSTANCE val) { m_hInstance = val; }

	
private:
	HWND createMessageWindow();
	int m_browserCount;
	int m_loopTime;
	bool m_multiThreadMsgLoop;
	HWND m_hMsgWnd;
	HINSTANCE m_hInstance;
};
#endif
