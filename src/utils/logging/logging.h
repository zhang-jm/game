#ifndef LOGGING_H
#define LOGGING_H

#include <spdlog/logger.h>

#define LOG logging()

void InitLogger(std::string logger_name);

spdlog::logger& logging();

#endif