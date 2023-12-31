#pragma once

//shared_ptr
#include <memory>

#include "../Macros.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

// Logger Macros
#define LOG_TRACE(...) Blank::Logger::getLogger()->trace(__VA_ARGS__) // VA ARGS just means forwards arguments from (...)
#define LOG_DEBUG(...) Blank::Logger::getLogger()->debug(__VA_ARGS__)
#define LOG_INFO(...) Blank::Logger::getLogger()->info(__VA_ARGS__)
#define LOG_WARN(...) Blank::Logger::getLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...) Blank::Logger::getLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...) Blank::Logger::getLogger()->critical(__VA_ARGS__)

namespace Blank 
{ 
	class ENGINE_API Logger
	{
	public:
		/*
		* @dev initializes default logger
		*/
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getLogger() { return m_logger; }
	private:
		static std::shared_ptr<spdlog::logger> m_logger;
	};
}