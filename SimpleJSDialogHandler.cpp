#include "SimpleJSDialogHandler.h"
#include <windows.h>
#include <tchar.h>

#pragma comment(lib, "User32.lib")

bool SimpleJSDialogHandler::OnJSDialog(CefRefPtr<CefBrowser> browser, const CefString& origin_url, JSDialogType dialog_type, const CefString& message_text, const CefString& default_prompt_text, CefRefPtr<CefJSDialogCallback> callback, bool& suppress_message)
{
	int mbType = MB_OK;
	const TCHAR* title = _T("警告！");
	switch (dialog_type)
	{
	case JSDIALOGTYPE_CONFIRM:
	{
		title = _T("确认");
		mbType = MB_OKCANCEL;
	}
		break;
	case JSDIALOGTYPE_PROMPT:
	{
		mbType = MB_OKCANCEL;
		title = _T("提示");
	}
		break;
	default:
		break;
	}

	const TCHAR* message = message_text.empty()? default_prompt_text.c_str() : message_text.c_str();
	int result = MessageBox(browser->GetHost()->GetWindowHandle(), message, title, mbType);
	if (result == IDOK)
		callback->Continue(true, "");

	return true;
}
