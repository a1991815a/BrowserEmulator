#ifndef __CEFDELEGATE_H__
#define __CEFDELEGATE_H__
#include "include/cef_app.h"
#include "CefAppFactory.h"
#include "CefMixedMessageLoop.h"

class CefDelegate
{
public:
	CefDelegate(HINSTANCE hInstance, LPTSTR lpCmdLine);

	bool init(CefRefPtr<CefCommandLine> command);

	int runMessageLoop();
	
	/*start getter setter*/
	HWND getWnd() const { return m_hWnd; }
	void setWnd(HWND val) { m_hWnd = val; }
	CefWindowInfo& getWindowInfo() { return m_windowInfo; }
	void setWindowInfo(const CefWindowInfo& val) { m_windowInfo = val; }
	CefSettings& getSetting() { return getSetting(); }
	void setSetting(const CefSettings& val) { setSetting(val); }
	const CefMainArgs& getMainArgs() const { return m_mainArgs; }
	void setMainArgs(const CefMainArgs& val) { m_mainArgs = val; }
	bool isMutilProcess() const { return m_bIsMutilProcess; }
	void setMutilProcess(bool val) { m_bIsMutilProcess = val; }
	CefAppFactory* getAppFactory() const { return m_pAppFactory; }
	void setAppFactory(CefAppFactory* val) { m_pAppFactory = val; }
	CefMixedMessageLoop* getMixedMessageLoop() const { return m_pMixedMessageLoop; }
	void setMixedMessageLoop(CefMixedMessageLoop* val) { m_pMixedMessageLoop = val; }
	/*end getter setter*/

private:
	HWND m_hWnd;
	CefWindowInfo m_windowInfo;
	CefSettings m_setting;
	CefMainArgs m_mainArgs;

	CefAppFactory* m_pAppFactory;
	CefMixedMessageLoop* m_pMixedMessageLoop;
private:
	static CefRefPtr<CefApp> s_pMainApp;
};
#endif
