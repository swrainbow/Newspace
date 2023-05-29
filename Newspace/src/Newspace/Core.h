#pragma once


#ifdef NSPACE_PLATFORM_WINDOWS
	#ifdef NSPACE_BUILD_DLL
		#define NSPACE_API __declspec(dllexport)
	#else
		#define NSPACE_API __declspec(dllimport)
	#endif
#else
	#error only suppors Windows!
#endif // DEBUG


#ifdef NSPACE_DEBUG
#define NSPACE_ENABLE_ASSERTS
#endif

#ifdef NSPACE_ENABLE_ASSERTS
#define NSPACE_ASSERT(x, ...) { if(!(x)) { NSPACE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define NSPACE_CORE_ASSERT(x, ...) { if(!(x)) { NSPACE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define HZ_ASSERT(x, ...)
#define HZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) ( 1 << x)
