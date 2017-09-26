#ifndef __LOG_H__
#define __LOG_H__
#include <wtypes.h>
#include <stdio.h>

void log(const char* format, const char* file, int line, ...);
void log(const wchar_t format, const wchar_t* file, int line, ...);

#ifdef _DEBUG
#define LOG(FORMAT, ...) log(FORMAT, __FILE__, __LINE__,##__VA_ARGS__)
#else
#define LOG(FORMAT, ...)
#endif
#endif
