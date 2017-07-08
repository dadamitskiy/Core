/// Copyright © Daniel Adamitskiy. All Rights Reserved.

#pragma once

#include "DA.Platform.h"

typedef char				int8;
typedef short				int16;
typedef int					int32;
typedef long long			int64;

typedef unsigned char		uint8;
typedef unsigned short		uint16;
typedef unsigned int		uint32;
typedef unsigned long long	uint64;

typedef void*				v32;

typedef wchar_t				wint8;

#if (DA_PLATFORM_WINDOWS)
	#define DA_INLINE				inline
	#define DA_FORCEINLINE			__forceinline
	#define DA_FORCENOINLINE		__declspec(noinline)
	#define DA_DEPRECATED(Message)	__declspec(deprecated(Message))
#else
	#define DA_INLINE
	#define DA_FORCEINLINE
	#define DA_FORCENOINLINE
	#define DA_DEPRECATED(Message)
#endif

namespace DA
{
namespace Type
{

/// Finds the first index of a character in a string.
/// @param string - The string to search through.
/// @param character - The character to search for.
/// @return The index of the character, or -1 if unsuccessful.
static int32 FirstIndexOf(const int8* string, const int8* character)
{
	if (string && character)
	{
		uint32 index = 0;
		
		while (string[index] != '\0')
		{
			if (string[index] == *character)
			{
				return index;
			}

			index++;
		}
	}

	return -1;
}

/// Finds the last index of a character in a string.
/// @param string - The string to search through.
/// @param character - The character to search for.
/// @return The index of the character, or -1 if unsuccessful.
static int32 LastIndexOf(const int8* string, const int8* character)
{
	int32 resultIndex = -1;

	if (string && character)
	{
		uint32 index = 0;

		while (string[index] != '\0')
		{
			if (string[index] == *character)
			{
				resultIndex = index;
			}

			index++;
		}
	}

	return resultIndex;
}

/// Finds the Nth index of a character in a string.
/// @param string - The string to search through.
/// @param character - The character to search for.
/// @param instanceOf - Instance of the character to search for.
/// @return The index of the character, or -1 if unsuccessful.
static int32 NthIndexOf(const int8* string, const int8* character, const int32 instanceOf)
{
	if (string && character)
	{
		uint32 index = 0;
		int32 foundInstances = 0;

		while (string[index] != '\0')
		{
			if (string[index] == *character)
			{
				foundInstances++;
				
				if (foundInstances == instanceOf)
				{
					return index;
				}
			}

			index++;
		}
	}

	return -1;
}

} // namespace Type
} // namespace DA
