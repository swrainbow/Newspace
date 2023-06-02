#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Newspace {
	class NSPACE_API Log
	{
	public:
		Log();
		~Log();
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

#define NSPACE_CORE_ERROR(...) ::Newspace::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NSPACE_CORE_WARN(...)  ::Newspace::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NSPACE_CORE_INFO(...)  ::Newspace::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NSPACE_CORE_TRACE(...) ::Newspace::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NSPACE_CORE_FATAL(...) ::Newspace::Log::GetCoreLogger()->fatal(__VA_ARGS__)



#define NSPACE_ERROR(...) ::Newspace::Log::GetClientLogger()->error(__VA_ARGS__)
#define NSPACE_WARN(...)  ::Newspace::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NSPACE_INFO(...)  ::Newspace::Log::GetClientLogger()->info(__VA_ARGS__)
#define NSPACE_TRACE(...) ::Newspace::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NSPACE_FATAL(...) ::Newspace::Log::GetClientLogger()->fatal(__VA_ARGS__)


