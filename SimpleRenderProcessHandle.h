#ifndef __SIMPLERENDERPROCESSHANDLE_H__
#define __SIMPLERENDERPROCESSHANDLE_H__
#include "include/cef_render_process_handler.h"

class SimpleRenderProcessHandle : public CefRenderProcessHandler
{
public:
	virtual void OnWebKitInitialized() override;

private:
	IMPLEMENT_REFCOUNTING(SimpleRenderProcessHandle);
};
#endif
