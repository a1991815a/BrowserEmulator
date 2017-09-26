#ifndef __BROWSERAPP_H__
#define __BROWSERAPP_H__
#include "include/cef_app.h"

class BrowserApp : public CefApp, public CefBrowserProcessHandler
{
public:
	BrowserApp(HWND hWnd = NULL);
	virtual void OnBeforeChildProcessLaunch(CefRefPtr<CefCommandLine> command_line) OVERRIDE;

	virtual void OnContextInitialized() OVERRIDE;

	virtual void OnRenderProcessThreadCreated(CefRefPtr<CefListValue> extra_info) OVERRIDE;

	virtual void OnScheduleMessagePumpWork(int64 delay_ms) OVERRIDE;

	virtual CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() OVERRIDE;

	virtual void OnBeforeCommandLineProcessing(const CefString& process_type, CefRefPtr<CefCommandLine> command_line) OVERRIDE;


	HWND getWnd() const { return m_hWnd; }
	void setWnd(HWND val) { m_hWnd = val; }
private:
	IMPLEMENT_REFCOUNTING(BrowserApp);
	HWND m_hWnd;
};
#endif
