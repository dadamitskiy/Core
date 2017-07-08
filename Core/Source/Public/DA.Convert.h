/// Copyright © Daniel Adamitskiy. All Rights Reserved.
 
#pragma once

#include "DA.Type.h"

namespace DA
{
namespace Math
{

/// Converts GBs to bytes.
/// @param gigabytes - Number of GBs to convert.
/// @return Bytes for the given GB amount.
constexpr const uint64 GigabytesToBytesBase2(const uint64 gigabytes)
{
	return (1024 * 1024 * 1024) * gigabytes;
}

/// Converts MBs to bytes.
/// @param megabytes - Number of MBs to convert.
/// @return Bytes for the given MB amount.
constexpr const uint64 MegabytesToBytesBase2(const uint64 megabytes)
{
	return (1024 * 1024) * megabytes;
}

/// Converts KBs to bytes.
/// @param kilobytes - Number of KBs to convert.
/// @return Bytes for the given KB amount.
constexpr const uint64 KilobytesToBytesBase2(const uint64 kilobytes)
{
	return 1024 * kilobytes;
}

} // namespace Math
} // namespace DA
