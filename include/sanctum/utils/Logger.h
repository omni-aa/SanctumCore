#ifndef SANCTUM_UTILS_LOGGER_H
#define SANCTUM_UTILS_LOGGER_H

#include <string>

namespace sanctum {
    namespace utils {

        class Logger {
        public:
            enum class Level {
                INFO,
                WARNING,
                ERROR,
                DEBUG
            };

            static void log(Level level, const std::string& message);
            static void info(const std::string& message);
            static void warning(const std::string& message);
            static void error(const std::string& message);
            static void debug(const std::string& message);

        private:
            static std::string levelToString(Level level);
        };

    } // namespace utils
} // namespace sanctum

#endif // SANCTUM_UTILS_LOGGER_H