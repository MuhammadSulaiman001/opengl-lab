#include "pch.h"

#include <filesystem>
#include <spdlog/sinks/basic_file_sink.h>

using namespace std;

namespace third_party_libs_tests
{
	// source https://github.com/gabime/spdlog
	TEST(ThirdPartyLibsTests, spdlog_should_work)
	{
		spdlog::info("Welcome to spdlog!");
		spdlog::error("Some error message with arg: {}", 1);
		spdlog::warn("Easy padding in numbers like {:08d}", 12);
		spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
	}

	TEST(ThirdPartyLibsTests, spdlog_creates_file_as_log_target)
	{
		filesystem::remove("logs/basic-log.txt");
		auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
		logger->info("Hi there!");
		logger->warn("Warning!");
		EXPECT_TRUE(filesystem::exists("logs/basic-log.txt"));
	}
}
