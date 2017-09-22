#ifndef __SIMPLELIFESPANHANDLER_H__
#define __SIMPLELIFESPANHANDLER_H__
#include "include/cef_life_span_handler.h"

class SimpleLifeSpanHandler : public CefLifeSpanHandler
{
public:
	SimpleLifeSpanHandler();
	virtual bool DoClose(CefRefPtr<CefBrowser> browser) override;

	virtual void OnAfterCreated(CefRefPtr<CefBrowser> browser) override;

	virtual void OnBeforeClose(CefRefPtr<CefBrowser> browser) override;

private:
	int m_browserCount;
private:
	IMPLEMENT_REFCOUNTING(SimpleLifeSpanHandler);
};
#endif
