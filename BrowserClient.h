#ifndef __BROWSERCLIENT_H__
#define __BROWSERCLIENT_H__
#include "include/cef_client.h"
#include "SimpleDialogHandler.h"
#include "SimpleDisplayHandler.h"
#include "SimpleFocusHandler.h"
#include "SimpleLifeSpanHandler.h"
#include "SimpleRenderHandler.h"
#include "SimpleRequestHandler.h"
#include "SimpleLoadHandler.h"
#include "SimpleJSDialogHandler.h"

class BrowserClient: public CefClient
{
public:
	static BrowserClient* getInstance();

	BrowserClient();

	virtual CefRefPtr<CefContextMenuHandler> GetContextMenuHandler() override;

	virtual CefRefPtr<CefDialogHandler> GetDialogHandler() override;

	virtual CefRefPtr<CefDisplayHandler> GetDisplayHandler() override;

	virtual CefRefPtr<CefDownloadHandler> GetDownloadHandler() override;

	virtual CefRefPtr<CefDragHandler> GetDragHandler() override;

	virtual CefRefPtr<CefFindHandler> GetFindHandler() override;

	virtual CefRefPtr<CefFocusHandler> GetFocusHandler() override;

	virtual CefRefPtr<CefGeolocationHandler> GetGeolocationHandler() override;

	virtual CefRefPtr<CefJSDialogHandler> GetJSDialogHandler() override;

	virtual CefRefPtr<CefKeyboardHandler> GetKeyboardHandler() override;

	virtual CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override;

	virtual CefRefPtr<CefLoadHandler> GetLoadHandler() override;

	virtual CefRefPtr<CefRenderHandler> GetRenderHandler() override;

	virtual CefRefPtr<CefRequestHandler> GetRequestHandler() override;

private:
	CefRefPtr<SimpleDialogHandler>		m_dialogHandler;
	CefRefPtr<SimpleDisplayHandler>		m_displayHandler;
	CefRefPtr<SimpleFocusHandler>		m_focusHandler;
	CefRefPtr<SimpleJSDialogHandler>	m_jsDialogHandler;
	CefRefPtr<SimpleLifeSpanHandler>	m_lifeSpanHandler;
	CefRefPtr<SimpleLoadHandler>		m_loadHandler;
	CefRefPtr<SimpleRenderHandler>		m_renderHandler;
	CefRefPtr<SimpleRequestHandler>		m_requestHandler;

	static BrowserClient* s_pInstance;
private:
	IMPLEMENT_REFCOUNTING(BrowserClient);
};
#endif
