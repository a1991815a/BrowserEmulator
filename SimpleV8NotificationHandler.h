#ifndef __SIMPLEV8HANDLER_H__
#define __SIMPLEV8HANDLER_H__
#include "include/cef_v8.h"

class SimpleV8NotificationHandler : public CefV8Handler
{
public:
	virtual bool Execute(const CefString& name, CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception) override;

private:
	IMPLEMENT_REFCOUNTING(SimpleV8NotificationHandler);
};
#endif