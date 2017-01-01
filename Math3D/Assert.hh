#pragma once
#include <string>
#include <cstdio>
#include <windows.h>

/**
* @def ASSERT(cnd)
* @brief Determine if @cnd is not fulfilled, then show a message box with the error.
*/
#ifdef NDEBUG
#define ASSERT(cnd, ...) (cnd)
#else
#define ASSERT(cnd, ...) \
		([&](decltype(cnd) &&c, const char* const f) { \
			if (!!c) return c; \
			char buffer[500]; \
			sprintf_s(buffer, "File: %s\nFunction: %-30.30s\nLine: %-5d\nContent: %s\nDescription: %s", __FILE__, f, __LINE__, #cnd, ##__VA_ARGS__, " "); \
			MessageBox(nullptr, buffer, nullptr, MB_OK | MB_ICONERROR); \
			exit(-1); \
		})(cnd, __FUNCTION__);
#endif


