#pragma once
#include <memory>
#include "Newspace/Core/Base.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Newspace {
	class Log
	{
	public:
		Log();
		~Log();
		static void Init();
		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

#define NSPACE_CORE_ERROR(...)    ::Newspace::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NSPACE_CORE_WARN(...)     ::Newspace::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NSPACE_CORE_INFO(...)     ::Newspace::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NSPACE_CORE_TRACE(...)    ::Newspace::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NSPACE_CORE_FATAL(...)    ::Newspace::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define NSPACE_CORE_CRITICAL(...) ::Newspace::Log::GetCoreLogger()->critical(__VA_ARGS__)




#define NSPACE_ERROR(...)      ::Newspace::Log::GetClientLogger()->error(__VA_ARGS__)
#define NSPACE_WARN(...)       ::Newspace::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NSPACE_INFO(...)       ::Newspace::Log::GetClientLogger()->info(__VA_ARGS__)
#define NSPACE_TRACE(...)      ::Newspace::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NSPACE_FATAL(...)      ::Newspace::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define NSPACE_CRITICAL(...)   ::Newspace::Log::GetClientLogger()->critical(__VA_ARGS__)



