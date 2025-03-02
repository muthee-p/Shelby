#pragma once

#ifdef SB_PLATFORM_WINDOWS
	#ifdef SB_BUILD_DLL
		#define SHELBY_API __declspec(dllexport)
	#else
		#define SHELBY_API __declspec(dllimport)
	#endif
#else
	#error Shelby only supports Windows!

#endif // DEBUG
