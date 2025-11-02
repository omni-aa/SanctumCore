#include "sanctum/utils/Logger.h"
#include <iostream>
#include <chrono>
#include <iomanip>

namespace sanctum {
    namespace utils {

        void Logger::log(Level level, const std::string& message) {
            auto now = std::chrono::system_clock::now();
            auto time_t = std::chrono::system_clock::to_time_t(now);

            std::cout << "[" << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S") << "] "
                      << "[" << levelToString(level) << "] "
                      << message << std::endl;
        }

        void Logger::info(const std::string& message) {
            log(Level::INFO, message);
        }

        void Logger::warning(const std::string& message) {
            log(Level::WARNING, message);
        }

        void Logger::error(const std::string& message) {
            log(Level::ERROR, message);
        }

        void Logger::debug(const std::string& message) {
            log(Level::DEBUG, message);
        }

        std::string Logger::levelToString(Level level) {
            switch(level) {
                case Level::INFO: return "INFO";
                case Level::WARNING: return "WARNING";
                case Level::ERROR: return "ERROR";
                case Level::DEBUG: return "DEBUG";
                default: return "UNKNOWN";
            }
        }

    } // namespace utils
} // namespace sanctum