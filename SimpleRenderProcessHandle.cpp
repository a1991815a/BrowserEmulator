#include "SimpleRenderProcessHandle.h"
#include "include\wrapper\cef_helpers.h"
#include <tchar.h>
#include "SimpleV8NotificationHandler.h"

void SimpleRenderProcessHandle::OnWebKitInitialized()
{
	FILE* f = NULL;
	std::string jscode;
	if (fopen_s(&f, "E:\\repo\\WinCef\\win32\\BrowserEmulator\\Debug\\js\\Notification.js", "rb+") == 0)
	{
		fseek(f, 0, SEEK_END);
		long fsize = ftell(f);
		char* fbuf = new char[fsize];
		rewind(f);
		fread_s(fbuf, fsize, 1, fsize, f);
		fclose(f);
		jscode += fbuf;
		delete[] fbuf;
	}

	if (!CefRegisterExtension("Notification", jscode, CefRefPtr<SimpleV8NotificationHandler>(new SimpleV8NotificationHandler())))
		MessageBox(NULL, _T("´íÎó"), _T("×¢²áÊ§°Ü"), MB_OK);
}
