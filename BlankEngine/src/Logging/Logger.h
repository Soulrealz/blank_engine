#pragma once

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

namespace Blank 
{
	class Logger
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getLogger() { return m_logger; }
	private:
		static std::shared_ptr<spdlog::logger> m_logger;
	};
}