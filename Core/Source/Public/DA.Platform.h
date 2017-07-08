/// Copyright © Daniel Adamitskiy. All Rights Reserved.

#pragma once

#if defined(_WIN32) && !defined(_WIN64)
	#define DA_PLATFORM_WINDOWS		1
	#define DA_PLATFORM_WIN32		1
	#define DA_PLATFORM_WIN64		0
	#define DA_PLATFORM_LINUX		0
	#define DA_PLATFORM_UNIX		0
	#define DA_PLATFORM_ANDROID		0
	#define DA_PLATFORM_APPLE		0
#elif defined(_WIN64)
	#define DA_PLATFORM_WINDOWS		1
	#define DA_PLATFORM_WIN32		0
	#define DA_PLATFORM_WIN64		1
	#define DA_PLATFORM_LINUX		0
	#define DA_PLATFORM_UNIX		0
	#define DA_PLATFORM_ANDROID		0
	#define DA_PLATFORM_APPLE		0
#elif defined(__linux__)
	#define DA_PLATFORM_WINDOWS		0
	#define DA_PLATFORM_WIN32		0
	#define DA_PLATFORM_WIN64		0
	#define DA_PLATFORM_LINUX		1
	#define DA_PLATFORM_UNIX		0
	#define DA_PLATFORM_ANDROID		0
	#define DA_PLATFORM_APPLE		0
#elif defined(__unix__)
	#define DA_PLATFORM_WINDOWS		0
	#define DA_PLATFORM_WIN32		0
	#define DA_PLATFORM_WIN64		0
	#define DA_PLATFORM_LINUX		0
	#define DA_PLATFORM_UNIX		1
	#define DA_PLATFORM_ANDROID		0
	#define DA_PLATFORM_APPLE		0
#elif defined(__ANDROID__)
	#define DA_PLATFORM_WINDOWS		0
	#define DA_PLATFORM_WIN32		0
	#define DA_PLATFORM_WIN64		0
	#define DA_PLATFORM_LINUX		0
	#define DA_PLATFORM_UNIX		0
	#define DA_PLATFORM_ANDROID		1
	#define DA_PLATFORM_APPLE		0
#elif defined(__APPLE__)
	#define DA_PLATFORM_WINDOWS		0
	#define DA_PLATFORM_WIN32		0
	#define DA_PLATFORM_WIN64		0
	#define DA_PLATFORM_LINUX		0
	#define DA_PLATFORM_UNIX		0
	#define DA_PLATFORM_ANDROID		0
	#define DA_PLATFORM_APPLE		1
#else
	#error Unknown platform detected.
#endif
