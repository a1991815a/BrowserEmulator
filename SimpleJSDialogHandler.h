#ifndef __SIMPLEJSDIALOGHANDLER_H__
#define __SIMPLEJSDIALOGHANDLER_H__
#include "include/cef_jsdialog_handler.h"

class SimpleJSDialogHandler : public CefJSDialogHandler
{
public:
	virtual bool OnJSDialog(CefRefPtr<CefBrowser> browser, const CefString& origin_url, JSDialogType dialog_type, const CefString& message_text, const CefString& default_prompt_text, CefRefPtr<CefJSDialogCallback> callback, bool& suppress_message) override;
	

private:
	IMPLEMENT_REFCOUNTING(SimpleJSDialogHandler);
};
#endif
