#include "BrowserClient.h"

BrowserClient* BrowserClient::s_pInstance = NULL;

BrowserClient* BrowserClient::getInstance()
{
	if (s_pInstance == NULL)
		s_pInstance = new BrowserClient();
	return s_pInstance;
}

BrowserClient::BrowserClient()
{
	m_dialogHandler = new SimpleDialogHandler();
	m_displayHandler = new SimpleDisplayHandler();
	m_focusHandler = new SimpleFocusHandler();
	m_jsDialogHandler = new SimpleJSDialogHandler();
	m_lifeSpanHandler = new SimpleLifeSpanHandler();
	m_loadHandler = new SimpleLoadHandler();
	m_renderHandler = new SimpleRenderHandler();
	m_requestHandler = new SimpleRequestHandler();
}

CefRefPtr<CefContextMenuHandler> BrowserClient::GetContextMenuHandler()
{
	return NULL;
}

CefRefPtr<CefDialogHandler> BrowserClient::GetDialogHandler()
{
	return m_dialogHandler;
}

CefRefPtr<CefDisplayHandler> BrowserClient::GetDisplayHandler()
{
	return m_displayHandler;
}

CefRefPtr<CefDownloadHandler> BrowserClient::GetDownloadHandler()
{
	return NULL;
}

CefRefPtr<CefDragHandler> BrowserClient::GetDragHandler()
{
	return NULL;
}

CefRefPtr<CefFindHandler> BrowserClient::GetFindHandler()
{
	return NULL;
}

CefRefPtr<CefFocusHandler> BrowserClient::GetFocusHandler()
{
	return m_focusHandler;
}

CefRefPtr<CefGeolocationHandler> BrowserClient::GetGeolocationHandler()
{
	return NULL;
}

CefRefPtr<CefJSDialogHandler> BrowserClient::GetJSDialogHandler()
{
	return m_jsDialogHandler;
}

CefRefPtr<CefKeyboardHandler> BrowserClient::GetKeyboardHandler()
{
	return NULL;
}

CefRefPtr<CefLifeSpanHandler> BrowserClient::GetLifeSpanHandler()
{
	return m_lifeSpanHandler;
}

CefRefPtr<CefLoadHandler> BrowserClient::GetLoadHandler()
{
	return m_loadHandler;
}

CefRefPtr<CefRenderHandler> BrowserClient::GetRenderHandler()
{
	return m_renderHandler;
}

CefRefPtr<CefRequestHandler> BrowserClient::GetRequestHandler()
{
	return m_requestHandler;
}
