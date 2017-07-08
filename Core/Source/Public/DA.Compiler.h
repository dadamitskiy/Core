/// Copyright © Daniel Adamitskiy. All Rights Reserved.

#pragma once

#if defined(_MSC_VER)
	#define DA_COMPILER_MSVC	1
	#define DA_COMPILER_CLANG	0
	#define DA_COMPILER_GCC		0
#elif (__clang__)
	#define DA_COMPILER_MSVC	0
	#define DA_COMPILER_CLANG	1
	#define DA_COMPILER_GCC		0
#elif (__GNUC__)
	#define DA_COMPILER_MSVC	0
	#define DA_COMPILER_CLANG	0
	#define DA_COMPILER_GCC		1
#else
	#error Attempting to compile with an unsupported compiler.
#endif
