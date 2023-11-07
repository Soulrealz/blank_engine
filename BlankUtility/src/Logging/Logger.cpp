#include "Logger.h"

namespace Blank
{
	// Init logger
	std::shared_ptr<spdlog::logger> Logger::m_logger;

	void Logger::init()
	{	
		//std::shared_ptr<spdlog::logger> Logger::m_logger;
		auto errorLogSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("error.log");
		errorLogSink->set_level(spdlog::level::warn);
		auto debugLogSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("debug.log");
		debugLogSink->set_level(spdlog::level::debug);
		//color, timestamp, name, message
		
		m_logger = std::make_shared<spdlog::logger>("Default");
		m_logger->set_pattern("%^[%T] %n: %v%$");
		m_logger->sinks().push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		m_logger->sinks().push_back(errorLogSink);
		m_logger->sinks().push_back(debugLogSink);
		m_logger->set_level(spdlog::level::trace);
		m_logger->flush_on(spdlog::level::trace);


		std::shared_ptr<spdlog::logger> m_debug_logger = std::make_shared<spdlog::logger>("Debug");
		m_debug_logger->sinks().push_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
		m_debug_logger->set_level(spdlog::level::trace);
		m_debug_logger->set_pattern("%^[%T] %n: %v%$");

		m_debug_logger->log(spdlog::level::critical, "hui s oko lapni go da te ne gleda");

	}
}