#include "SimpleLoadHandler.h"

void SimpleLoadHandler::OnLoadError(
	CefRefPtr<CefBrowser> browser, 
	CefRefPtr<CefFrame> frame, 
	ErrorCode errorCode, 
	const CefString& errorText, 
	const CefString& failedUrl)
{
	wprintf(L"%s: %s", failedUrl.c_str(), errorText.c_str());
}
