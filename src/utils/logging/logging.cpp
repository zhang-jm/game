#include "logging.h"

#include <vector>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <spdlog/spdlog.h>
#include <spdlog/async.h>
#include <spdlog/async_logger.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

#define QUEUE_SIZE 8192
#define NUM_THREADS 1

static std::shared_ptr<spdlog::async_logger> logger = nullptr;

void InitLogger(std::string logger_name) {
    try {
        spdlog::init_thread_pool(QUEUE_SIZE, NUM_THREADS);
        spdlog::flush_every(std::chrono::seconds(1));

        auto t = std::time(nullptr);
        std::ostringstream oss;
        oss << "log_" << std::put_time(gmtime(&t), "%F_%H-%M-%S") << ".txt";

        auto stdout_sink = std::make_shared<spdlog::sinks::stdout_sink_mt >();
        auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(oss.str());
        std::vector<spdlog::sink_ptr> sinks{ stdout_sink, file_sink };

        logger = std::make_shared<spdlog::async_logger>(logger_name, begin(sinks), end(sinks), spdlog::thread_pool(), spdlog::async_overflow_policy::block);

        logger->set_pattern("[%D %T.%f] [%^%l%$] [%n-%t] %v");
        logger->set_level(spdlog::level::debug);
        logger->flush_on(spdlog::level::info);
    }
    catch (const spdlog::spdlog_ex& ex) {
        std::cout << "Log initialization failed: " << ex.what() << std::endl;
    }
}

spdlog::logger& logging() {
    return *logger;
}