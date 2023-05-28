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
