/// Copyright © Daniel Adamitskiy. All Rights Reserved.
 
#pragma once

#include "DA.Type.h"

namespace DA
{
namespace Core
{

/// Computes the next power of two.
/// @param value - Value to compute the next power of two with.
/// @return The next power of two.
static uint32 ComputeNextPowerOfTwo(uint32 value)
{
	value--;
	value |= value >> 1;
	value |= value >> 2;
	value |= value >> 4;
	value |= value >> 8;
	value |= value >> 16;
	value++;

	return value;
}

/// Checks if a value is a power of two.
/// @param value - Value to check.
/// @return True if the number is a power of two, false otherwise.
static bool IsPowerOfTwo(uint32 value)
{
	return value && !(value & (value - 1));
}

} // namespace Core
} // namespace DA
