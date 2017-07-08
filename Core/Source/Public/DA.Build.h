/// Copyright © Daniel Adamitskiy. All Rights Reserved.

#pragma once

#if defined(_DEBUG)
	#define DA_BUILD_DEBUG		1
	#define DA_BUILD_RELEASE	0
#else
	#define DA_BUILD_DEBUG		0
	#define DA_BUILD_RELEASE	1
#endif
