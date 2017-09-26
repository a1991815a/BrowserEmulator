#include "SimpleV8NotificationHandler.h"

bool SimpleV8NotificationHandler::Execute(const CefString& name, CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception)
{
	MessageBox(NULL, name.c_str(), name.c_str(), MB_OK);
	return true;
}
