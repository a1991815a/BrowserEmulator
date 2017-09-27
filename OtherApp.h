#ifndef __OTHERAPP_H__
#define __OTHERAPP_H__
#include "include/cef_app.h"

class OtherApp : public CefApp
{
public:
	OtherApp();
private:
	IMPLEMENT_REFCOUNTING(OtherApp);
	DISALLOW_COPY_AND_ASSIGN(OtherApp);
};
#endif
