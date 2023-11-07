#pragma once

//shared_ptr
#include <memory>

#include "../Macros.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"


namespace Blank 
{ 
	class ENGINE_API Logger
	{
	public:
		/*
		* @dev initializes debug and default loggers
		*/
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getLogger() { return m_logger; }
	private:
		static std::shared_ptr<spdlog::logger> m_logger;
	};
}