#ifndef __SIMPLERENDERHANDLER_H__
#define __SIMPLERENDERHANDLER_H__
#include "include/cef_render_handler.h"

class SimpleRenderHandler : public CefRenderHandler
{
public:
	virtual bool GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect) override;


	virtual void OnPaint(CefRefPtr<CefBrowser> browser, PaintElementType type, const RectList& dirtyRects, const void* buffer, int width, int height) override;

private:
	IMPLEMENT_REFCOUNTING(SimpleRenderHandler);
};
#endif
