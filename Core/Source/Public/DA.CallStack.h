/// Copyright © Daniel Adamitskiy. All Rights Reserved.

#pragma once

#include "DA.Module.h"
#include "DA.Platform.h"
#include "DA.Type.h"
#include <vector>

namespace DA
{
namespace Core
{

class CORE_API CallStackFrame
{
public:

	/// Constructor.
	/// @param address - Address of this frame.
	/// @param fileName - File name of this frame.
	/// @param functionName - The file name this frame is in.
	/// @param lineNumber - Line number the frame is on.
	explicit DA_FORCEINLINE CallStackFrame(const uint64 address, const int8* fileName, const int8* functionName, const int32 lineNumber)
		: address(address)
		, file_name(fileName)
		, function_name(functionName)
		, line_number(lineNumber)
	{
	}

	/// Destructor.
	DA_FORCEINLINE ~CallStackFrame()
	{
	}

	/// Gets this frame's address.
	/// @return The address of the call stack frame.
	const DA_FORCEINLINE uint64 GetAddress() const { return address; }

	/// Gets the file name for this frame.
	/// @return The file name of the frame.
	const DA_FORCEINLINE int8* GetFileName() const { return file_name; }

	/// Gets this frame's function name.
	/// @return The function name of this frame.
	const DA_FORCEINLINE int8* GetFunctionName() const { return function_name; }

	/// Gets this frame's line number.
	/// @return The line number of this frame.
	const DA_FORCEINLINE int32 GetLineNumber() const { return line_number; }

private:
	
	const uint64 address;
	const int8* file_name;
	const int8* function_name;
	const int32 line_number;
};

class CallStack
{
public:

	/// Constructor.
	CORE_API CallStack();

	/// Destructor.
	CORE_API ~CallStack();

	/// Captures current call stack information.
	/// @return True on successful capture, false otherwise.
	CORE_API bool CaptureCallStackInfo();

	/// Output call stack info and cleanup memory.
	CORE_API void OutputCallStackInfo();

	/// Get the call stack frame info.
	/// @return Vector of call stack frames.
	DA_FORCEINLINE std::vector<CallStackFrame> GetCallStackInfo() const { return call_stack_frames; }

private:

	std::vector<CallStackFrame> call_stack_frames;
};

} // namespace Core
} // namespace DA
