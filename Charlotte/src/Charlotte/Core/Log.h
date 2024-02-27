#pragma once

#include "CharCore.h"
#include <utility>
#include <string>

namespace Charlotte {
    enum LogLevel {
        LOG_LEVEL_FATAL = 0,
        LOG_LEVEL_ERROR = 1,
        LOG_LEVEL_WARN  = 2,
        LOG_LEVEL_INFO  = 3,
        LOG_LEVEL_DEBUG = 4
    };

    namespace Log {

        template<typename ... Args>
        void Output(const LogLevel& level, const char* message, Args&& ... args) {
            // Logs a formatted string to the console
            // also colors it accordingly using ANSI escape codes
            // TODO: Platform specific logging / colors
            // because ANSI colors arent the best solution
            static const std::string levelStrings[5] = {
                "\e[41m[FATAL] ",
                "\e[0;31m[ERROR] ",
                "\e[0;33m[WARN]  ",
                "\e[0;32m[INFO]  ",
                "\e[0;35m[Debug] "
            };

            // Format output message with level tag, and new line 
            // and also ANSI color reset
            std::string outString = levelStrings[level] + message + "\e[0m\n";

            // TODO: make this not throw a warning! dipshit
            printf(outString.c_str(), std::forward<Args>(args)...);
        }
    
    }
}

/**
*   Logs a fatal level message, used for errors that will prevent the program
*   from running any further
*/
#define LogFatal(message, ...) Charlotte::Log::Output(Charlotte::LOG_LEVEL_FATAL, message, ##__VA_ARGS__)

/**
*   Logs an error level message, for when the application can
*   still run, but might not work as expected
*/
#define LogError(message, ...) Charlotte::Log::Output(Charlotte::LOG_LEVEL_ERROR, message, ##__VA_ARGS__)

/**
*   Logs a warning level message, used for when theres a problem
*   but its not serious, or is handled by the program
*/
#define LogWarn(message, ...) Charlotte::Log::Output(Charlotte::LOG_LEVEL_WARN, message, ##__VA_ARGS__)

/**
*   Logs an info level message, used to display information to
*   the developer
*/
#define LogInfo(message, ...) Charlotte::Log::Output(Charlotte::LOG_LEVEL_INFO, message, ##__VA_ARGS__)

/**
*   Logs a debug level message, should be used temporarly
*   for checking random shit
*/
#define LogDebug(message, ...) Charlotte::Log::Output(Charlotte::LOG_LEVEL_DEBUG, message, ##__VA_ARGS__)