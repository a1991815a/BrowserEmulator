#include "include/cef_app.h"
#include <tchar.h>
#include "SimpleApp.h"

cef_string_t newString(const cef_char_t* str, size_t len, int isCopy = TRUE)
{
	cef_string_t tstr = {};
	cef_string_set(str, len, &tstr, isCopy);
	return tstr;
}

#define newConstString(str) newString(str, sizeof(str) / sizeof(cef_char_t), FALSE)


int APIENTRY wWinMain(
	_In_ HINSTANCE hInstance, 
	_In_opt_ HINSTANCE hPrevInstance, 
	_In_ LPWSTR lpCmdLine, 
	_In_ int nShowCmd)
{
	UNREFERENCED_PARAMETER(hInstance);
	UNREFERENCED_PARAMETER(hPrevInstance);
	CefEnableHighDPISupport();

	CefSettings cefSettings;
	cefSettings.no_sandbox = true;
	cefSettings.locale = newString(_T("zh-CN"), 5);
	//cefSettings.locales_dir_path = newConstString(_T("E:\\repo\\WinCef\\Resources\\locales"));

	CefMainArgs args(hInstance);
	int exitCode = CefExecuteProcess(args, NULL, NULL);
	if (exitCode > 0)
	{
		printf("CefExecuteProcess failure: %d", exitCode);
		return exitCode;
	}

	CefRefPtr<SimpleApp> app(new SimpleApp());
	CefInitialize(args, cefSettings, app.get(), NULL);

	CefRunMessageLoop();

	CefShutdown();
	return 0;
}