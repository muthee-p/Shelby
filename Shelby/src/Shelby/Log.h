#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
//#include "spdlog/fmt/ostr.h"

namespace Shelby {

	class SHELBY_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//core log macros
#define SB_CORE_TRACE(...) ::Shelby::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SB_CORE_INFO(...) ::Shelby::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SB_CORE_WARN(...) ::Shelby::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SB_CORE_ERROR(...) ::Shelby::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SB_CORE_FATAL(...) ::Shelby::Log::GetCoreLogger()->fatal(__VA_ARGS__)


//client log macros
#define SB_TRACE(...) ::Shelby::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SB_INFO(...) ::Shelby::Log::GetClientLogger()->info(__VA_ARGS__)
#define SB_WARN(...) ::Shelby::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SB_ERROR(...) ::Shelby::Log::GetClientLogger()->error(__VA_ARGS__)
#define SB_FATAL(...) ::Shelby::Log::GetClientLogger()->fatal(__VA_ARGS__)