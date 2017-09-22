#include "SimpleClient.h"

SimpleClient::SimpleClient()
{
	m_dialogHandler = new SimpleDialogHandler();
	m_displayHandler = new SimpleDisplayHandler();
	m_focusHandler = new SimpleFocusHandler();
	m_jsDialogHandler = new SimpleJSDialogHandler();
	m_lifeSpanHandler = new SimpleLifeSpanHandler();
	m_renderHandler = new SimpleRenderHandler();
	m_loadHandler = new SimpleLoadHandler();
}

SimpleClient::~SimpleClient()
{
}

CefRefPtr<CefDialogHandler> SimpleClient::GetDialogHandler()
{
	return this->m_dialogHandler;
}

CefRefPtr<CefDisplayHandler> SimpleClient::GetDisplayHandler()
{
	return this->m_displayHandler;
}

CefRefPtr<CefFocusHandler> SimpleClient::GetFocusHandler()
{
	return this->m_focusHandler;
}

CefRefPtr<CefJSDialogHandler> SimpleClient::GetJSDialogHandler()
{
	return this->m_jsDialogHandler;
}

CefRefPtr<CefLifeSpanHandler> SimpleClient::GetLifeSpanHandler()
{
	return this->m_lifeSpanHandler;
}

CefRefPtr<CefRenderHandler> SimpleClient::GetRenderHandler()
{
	return this->m_renderHandler;
}

CefRefPtr<CefLoadHandler> SimpleClient::GetLoadHandler()
{
	return this->m_loadHandler;
}
