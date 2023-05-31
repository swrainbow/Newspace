#pragma once

#ifdef NSPACE_PLATFORM_WINDOWS
#if NSPACE_DYNAMIC_LINK
#ifdef NSPACE_BUILD_DLL
#define HAZEL_API __declspec(dllexport)
#else
#define HAZEL_API __declspec(dllimport)
#endif
#else
#define NSPACE_API
#endif
#else
#error NSPACE only supports Windows! 
#endif

#ifdef NSPACE_DEBUG
#define NSPACE_ENABLE_ASSERTS
#endif

#ifdef NSPACE_ENABLE_ASSERTS
#define NSPACE_ASSERT(x, ...) { if(!(x)) { NSPACE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define NSPACE_CORE_ASSERT(x, ...) { if(!(x)) { NSPACE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define NSPACE_ASSERT(x, ...)
#define NSPACE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define NSPACE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)