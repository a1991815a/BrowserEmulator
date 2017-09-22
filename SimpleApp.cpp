#include "SimpleApp.h"
#include "include\views\cef_window_delegate.h"
#include "include\views\cef_window.h"
#include "include\wrapper\cef_helpers.h"
#include "SimpleClient.h"

void SimpleApp::OnContextInitialized()
{
	CEF_REQUIRE_UI_THREAD();

	CefBrowserSettings browserSettings = {};
	const char* url = "http://www.baidu.com";

	CefRefPtr<SimpleClient> client = new SimpleClient();

	CefWindowInfo windowInfo = {};
	windowInfo.SetAsPopup(NULL, "WinText");

	//CefRefPtr<SimpleHandler> handler(new SimpleHandler());
	if(!CefBrowserHost::CreateBrowser(windowInfo, client, url, browserSettings, NULL))
		printf("´´½¨Browser´íÎó£¡\n");
}
