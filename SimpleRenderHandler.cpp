#include "SimpleRenderHandler.h"

bool SimpleRenderHandler::GetViewRect(CefRefPtr<CefBrowser> browser, CefRect& rect)
{
	return true;
}

void SimpleRenderHandler::OnPaint(CefRefPtr<CefBrowser> browser, PaintElementType type, const RectList& dirtyRects, const void* buffer, int width, int height)
{
	
}
