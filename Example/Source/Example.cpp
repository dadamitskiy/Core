/**
 * The MIT License (MIT)
 *
 * Copyright © Daniel Adamitskiy. All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include <Core.h>

int main(int argc, char* argv[])
{
	// Check if you're in debug or release with:
#if defined(DA_BUILD_DEBUG) && (DA_BUILD_DEBUG == 1)
	int inDebug = 1;
	int inRelease = 0;
#elif defined (DA_BUILD_RELEASE) && (DA_BUILD_RELEASE == 1)
	int inDebug = 0;
	int inRelease = 1;
#endif

	// To capture a callstack while the program is crashing, use the CallStack class.
	// CaptureCallStackInfo will capture the callstack data
	// You can print it out by calling OutputCallstackInfo
	// DA::Core::CallStack callStack;

	// Determined the type of compiler you're on with: 
#if (DA_COMPILER_MSVC)	
	// MSVC specific code
#elif (DA_COMPILER_CLANG)
	// Clang specific code
#elif (DA_COMPILER_GCC)
	// GCC specific code
#endif

	// Utilize DA::IO namespace to:
	// - Open files
	// - Flush files
	// - Write out to a file
	// - Close files
	// DA::IO::OpenFile("somefile.txt", DA::IO::FileAccessMode::Write);

	// Also detectable is the platform you are currently on. Supported platforms include:
	// - DA_PLATFORM_WINDOWS		
	// - DA_PLATFORM_WIN32		
	// - DA_PLATFORM_WIN64		
	// - DA_PLATFORM_LINUX		
	// - DA_PLATFORM_UNIX		
	// - DA_PLATFORM_ANDROID		
	// - DA_PLATFORM_APPLE		

	return 0;
}
