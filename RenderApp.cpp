#include "RenderApp.h"



void RenderApp::OnBrowserCreated(CefRefPtr<CefBrowser> browser)
{
	
}

void RenderApp::OnWebKitInitialized()
{
	
}

CefRefPtr<CefRenderProcessHandler> RenderApp::GetRenderProcessHandler()
{
	return this;
}
