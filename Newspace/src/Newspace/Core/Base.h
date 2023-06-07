#pragma once
#include <memory>
// Platform detection using predefined macros
#ifdef _WIN32
	/* Windows x64/x86 */
#ifdef _WIN64
	/* Windows x64  */
#define NSPACE_PLATFORM_WINDOWS
#else
	/* Windows x86 */
#error "x86 Builds are not supported!"
#endif
#elif defined(__APPLE__) || defined(__MACH__)
#include <TargetConditionals.h>
/* TARGET_OS_MAC exists on all the platforms
 * so we must check all of them (in this order)
 * to ensure that we're running on MAC
 * and not some other Apple platform */
#if TARGET_IPHONE_SIMULATOR == 1
#error "IOS simulator is not supported!"
#elif TARGET_OS_IPHONE == 1
#define NSPACE_PLATFORM_IOS
#error "IOS is not supported!"
#elif TARGET_OS_MAC == 1
#define NSPACE_PLATFORM_MACOS
#error "MacOS is not supported!"
#else
#error "Unknown Apple platform!"
#endif


#elif defined(__ANDROID__)
#define NSPACE_PLATFORM_ANDROID
#error "Android is not supported!"
#elif defined(__linux__)
#define NSPACE_PLATFORM_LINUX
#error "Linux is not supported!"
#else
/* Unknown compiler/platform */
#error "Unknown platform!"
#endif // End of platform detection

#ifdef NSPACE_DEBUG
#if defined(NSPACE_PLATFORM_WINDOWS)
#define NSPACE_DEBUGBREAK() __debugbreak()
#elif defined(NSPACE_PLATFORM_LINUX)
#include <signal.h>
#define NSPACE_DEBUGBREAK() raise(SIGTRAP)
#else
#error "Platform doesn't support debugbreak yet!"
#endif
#define NSPACE_ENABLE_ASSERTS
#else
#define NSPACE_DEBUGBREAK()
#endif

#ifdef NSPACE_ENABLE_ASSERTS
#define NSPACE_ASSERT(x, ...) { if(!(x)) { NSPACE_ERROR("Assertion Failed: {0}", __VA_ARGS__); NSPACE_DEBUGBREAK(); } }
#define NSPACE_CORE_ASSERT(x, ...) { if(!(x)) { NSPACE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); NSPACE_DEBUGBREAK(); } }
#else
#define NSPACE_ASSERT(x, ...)
#define NSPACE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define NSPACE_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Newspace {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}
