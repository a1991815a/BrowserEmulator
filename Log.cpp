#include "Log.h"
#include <varargs.h>

char cBuf[4096] = {};
wchar_t wBuf[4096] = {};

void log(const char* format, const char* file, int line, ...)
{
	sprintf_s(cBuf, "file: %s line: %d\n%s:%s", file, line, "log", format);
	va_list ap;
	va_start(ap, format);
	vprintf_s(cBuf, ap);
	va_end(ap);
}

void log(const wchar_t format, const wchar_t* file, int line, ...)
{
	sprintf_s(cBuf, "file: %s line: %d\n%s:%ls", file, line, "log", format);
	va_list ap;
	va_start(ap, format);
	vprintf_s(cBuf, ap);
	va_end(ap);
}

