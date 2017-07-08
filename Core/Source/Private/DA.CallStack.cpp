/// Copyright © Daniel Adamitskiy. All Rights Reserved.

#include "DA.CallStack.h"
#include "DA.Compiler.h"
#include <iostream>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

#pragma warning(push)
#pragma warning(disable : 4091)
#include <DbgHelp.h>
#pragma warning(pop)

#pragma comment(lib, "Dbghelp.lib")

namespace DA
{
namespace Core 
{

CallStack::CallStack()
{
}

CallStack::~CallStack()
{
}

bool CallStack::CaptureCallStackInfo()
{
	const int32 framesToSkip = 0;
	const int32 framesToCapture = 25;
	v32 callstack[framesToCapture];
	const HANDLE process = GetCurrentProcess();

	if (SymInitialize(process, nullptr, true))
	{
		const WORD frames = CaptureStackBackTrace(framesToSkip, framesToCapture, callstack, nullptr);
		SYMBOL_INFO* symbol = reinterpret_cast<SYMBOL_INFO*>(calloc(sizeof(SYMBOL_INFO) + 256 * sizeof(char), 1));
		symbol->MaxNameLen = 255;
		symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
		SymSetOptions(SYMOPT_LOAD_LINES);

		for (int32 iter = 0; iter < frames; ++iter)
		{
			SymFromAddr(process, reinterpret_cast<DWORD64>(callstack[iter]), 0, symbol);

			IMAGEHLP_LINE line;
			DWORD displacement;
			line.SizeOfStruct = sizeof(IMAGEHLP_LINE);

			SymGetLineFromAddr(process, reinterpret_cast<DWORD64>(callstack[iter]), &displacement, &line);

			int8* functionName = new int8[256];
			strcpy_s(functionName, strlen(symbol->Name) + 1, symbol->Name);
			int8* file = new int8[256];
			strcpy_s(file, strlen(line.FileName) + 1, line.FileName);

			CallStackFrame frame(symbol->Address, file, functionName, line.LineNumber);
			call_stack_frames.push_back(frame);
		}

		free(symbol);
	}

	return true;
}

void CallStack::OutputCallStackInfo()
{
	for (int32 i = 0; i < call_stack_frames.size(); ++i)
	{
		printf("0x%0X %s - Line %i (%s)\n", static_cast<uint32>(call_stack_frames[i].GetAddress()), call_stack_frames[i].GetFunctionName(), call_stack_frames[i].GetLineNumber(), call_stack_frames[i].GetFileName());
		
		if (call_stack_frames[i].GetFileName())
		{
			delete call_stack_frames[i].GetFileName();
		}

		if (call_stack_frames[i].GetFunctionName())
		{
			delete call_stack_frames[i].GetFunctionName();
		}
	}
}

} // namespace Core
} // namespace DA
