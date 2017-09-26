#include "BrowserApp.h"
#include "include\wrapper\cef_helpers.h"
#include "BrowserClient.h"

BrowserApp::BrowserApp(HWND hWnd)
	:m_hWnd(hWnd)
{

}

void BrowserApp::OnBeforeChildProcessLaunch(CefRefPtr<CefCommandLine> command_line)
{
	
}

void BrowserApp::OnContextInitialized()
{
	CEF_REQUIRE_UI_THREAD();

	CefBrowserSettings browserSettings = {};
	const CefString& url = CefCommandLine::GetGlobalCommandLine()->GetSwitchValue("url");

	CefRefPtr<BrowserClient> client(BrowserClient::getInstance());

	CefWindowInfo windowInfo = {};
	if (getWnd() == NULL)
		windowInfo.SetAsPopup(NULL, "Browser");
	else
	{
		RECT rect = {};
		::GetClientRect(getWnd(), &rect);
		windowInfo.SetAsChild(getWnd(), rect);
	}

	if (!CefBrowserHost::CreateBrowser(windowInfo, client, url, browserSettings, NULL))
		printf("´´½¨Browser´íÎó£¡\n");
}

void BrowserApp::OnRenderProcessThreadCreated(CefRefPtr<CefListValue> extra_info)
{
	
}

void BrowserApp::OnScheduleMessagePumpWork(int64 delay_ms)
{
	
}

CefRefPtr<CefBrowserProcessHandler> BrowserApp::GetBrowserProcessHandler()
{
	return this;
}

void BrowserApp::OnBeforeCommandLineProcessing(const CefString& process_type, CefRefPtr<CefCommandLine> command_line)
{
	if (!command_line->HasSwitch("url"))
		command_line->AppendSwitchWithValue("url", "http://192.168.1.250:50082/");
}
