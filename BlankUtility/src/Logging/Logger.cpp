#include "Logger.h"

namespace Blank
{
	// logger definition
	std::shared_ptr<spdlog::logger> Logger::m_logger;

	void Logger::init()
	{	
		//file sinks
		auto errorLogSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("Logs/error.log");
		errorLogSink->set_level(spdlog::level::warn);
		auto debugLogSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("Logs/debug.log");
		debugLogSink->set_level(spdlog::level::debug);		
		
		//Logger config
		m_logger = std::make_shared<spdlog::logger>("Default");
		//color, timestamp, name, message
		m_logger->set_pattern("%^[%T] %n: %v%$");
		m_logger->sinks().push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		m_logger->sinks().push_back(errorLogSink);
		m_logger->sinks().push_back(debugLogSink);
		m_logger->set_level(spdlog::level::trace);
		m_logger->flush_on(spdlog::level::trace);
	}
}