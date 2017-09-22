#ifndef __SIMPLELOADHANDLER_H__
#define __SIMPLELOADHANDLER_H__
#include "include/cef_load_handler.h"

class SimpleLoadHandler : public CefLoadHandler
{
public:
	

	virtual void OnLoadError(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, ErrorCode errorCode, const CefString& errorText, const CefString& failedUrl) override;

private:
	IMPLEMENT_REFCOUNTING(SimpleLoadHandler);
};
#endif
