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

#ifdef SB_ENABLE_ASSERTS
	#define SB_ASSERT(x, ...) { if(!(x)) { SB_ERROR("Assertion Failed: { 0 }", __VA_ARGS__); __debugbreak(); }}
	#define SB_CORE_ASSERT(x, ...) { if(!(x)) { SB_CORE_ERROR("Assertion Failed: { 0 }", __VA_ARGS__); __debugbreak(); }}
#else
	#define SB_ASSERT(x, ...)
	#define SB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
