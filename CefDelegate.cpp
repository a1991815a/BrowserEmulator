#include "CefDelegate.h"
#include "Log.h"

CefRefPtr<CefApp> CefDelegate::s_pMainApp;

CefDelegate::CefDelegate(HINSTANCE hInstance, LPTSTR lpCmdLine)
	:m_hWnd(NULL), m_windowInfo(), m_setting(), m_mainArgs(hInstance)
{
	//本地化谷歌浏览器
	CefString local("zh-CN");
	m_setting.locale = *local.DetachToUserFree();
	m_setting.no_sandbox = true;
	//m_setting.multi_threaded_message_loop = true;
}

bool CefDelegate::init(CefRefPtr<CefCommandLine> command)
{
	CefEnableHighDPISupport();

	const std::string& type = command->GetSwitchValue("type");
	CefRefPtr<CefApp> app;
	if (type == "browser" || type.empty())
		app = m_pAppFactory->createBrowserApp(m_hWnd);
	else if (type == "renderer")
		app = m_pAppFactory->createRenderApp(m_hWnd);
	else
		app = m_pAppFactory->createOtherApp(type, m_hWnd);

	if (app.get() == NULL)
	{
		LOG("创建CefApp失败。也许是参数type:%s错误？", type.c_str());
		return false;
	}

	int result = CefExecuteProcess(m_mainArgs, app, NULL);
	if (result > 0)
	{
		LOG("CefExecuteProcess失败， exitCode=%d", result);
		return false;
	}

	if (!CefInitialize(m_mainArgs, m_setting, app.get(), NULL))
	{
		LOG("CefInitialize失败");
		return false;
	};

	CefDelegate::s_pMainApp = app;
	return true;
}

int CefDelegate::runMessageLoop()
{
	//if (m_setting.multi_threaded_message_loop)
		::CefRunMessageLoop();
// 	else
// 		m_pMixedMessageLoop->runMessageLoop();
	::CefShutdown();

	return 0;
}
