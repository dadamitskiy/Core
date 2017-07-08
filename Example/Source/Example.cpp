/// Copyright © Daniel Adamitskiy. All Rights Reserved.

#include <DA.Core.h>

int GlobalFunc(int a, float b)
{
	return a + (int)b;
}

class SomeClass
{
public:

	int MemberFunc(int a, float b) 
	{
		return a + (int)b;
	}
};

Delegate<int(int, float)> gGlobalFunctionDelegate(Delegate<int(int, float)>::Create<&GlobalFunc>());
Delegate<int(int, float)> gMemberFunctionDelegate;

int main(int32 argc, int8** argv)
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

	// Call the global/static function delegate.
	int result = gGlobalFunctionDelegate(5, 10.f);
	printf("gGlobalFunctionDelegate result=%d\n", result);

	// Call the member function delegate.
	SomeClass* sc = new SomeClass();
	gMemberFunctionDelegate = gMemberFunctionDelegate.Create<SomeClass, &SomeClass::MemberFunc>(sc);
	result = gMemberFunctionDelegate(result, 5.f);
	printf("gMemberFunctionDelegate result=%d\n", result);
	delete sc;
	sc = nullptr;

	return 0;
}
