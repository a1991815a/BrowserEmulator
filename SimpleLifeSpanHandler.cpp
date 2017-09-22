#include "SimpleLifeSpanHandler.h"
#include "include\wrapper\cef_helpers.h"
#include "include\cef_app.h"

SimpleLifeSpanHandler::SimpleLifeSpanHandler()
	:m_browserCount(0)
{

}

bool SimpleLifeSpanHandler::DoClose(CefRefPtr<CefBrowser> browser)
{
	CEF_REQUIRE_UI_THREAD();
	if(m_browserCount != 0)
		--m_browserCount;
	return false;
}

void SimpleLifeSpanHandler::OnAfterCreated(CefRefPtr<CefBrowser> browser)
{
	CEF_REQUIRE_UI_THREAD();
	++m_browserCount;
}

void SimpleLifeSpanHandler::OnBeforeClose(CefRefPtr<CefBrowser> browser)
{
	CEF_REQUIRE_UI_THREAD();
	if (m_browserCount == 0)
		CefQuitMessageLoop();
}
