#include "log.h"
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

static LogLevel_t active_level;
static uint32_t active_zones;

static const char* str_error = "ERROR";
static const char* str_info = "INFO";
static const char* str_debug = "DEBUG";
static const char* str_unknown = "UNKNOWN";

static const char* GetLevelName(LogLevel_t level)
{
    switch(level) {
        case LOG_ERROR:
            return str_error;
            break;
        case LOG_INFO:
            return str_info;
            break;
        case LOG_DEBUG:
            return str_debug;
            break;
        default:
            return str_unknown;
            break;
    }
}

static const char* GetZoneName(uint32_t zone)
{
    switch(zone) {
        case ZONE_MAIN:
            return "main";
            break;
        case ZONE_CPU:
            return "cpu";
            break;
        default:
            return str_unknown;
            break;
    }
}

static void LogWithTimestamp(LogLevel_t level, uint32_t zone, const char* format, va_list args)
{
    time_t unixtime;
    struct tm* timeptr;
    time(&unixtime);
    timeptr = localtime(&unixtime);
    
    static char buffer[64];
    strftime(buffer, sizeof(buffer), "%m/%d %H:%M:%S", timeptr);
    fputs(buffer, stderr);
    fprintf(stderr, " %s/%s: ", GetZoneName(zone), GetLevelName(level));
    vfprintf(stderr, format, args);
    fputs("\r\n", stderr);
}

void LogError(const char* format, ...) {
    va_list args;
    va_start(args, format);
    LogWithTimestamp(LOG_ERROR, 0, format, args);
    va_end(args);
}

void LogInfo(uint32_t zone, const char* format, ...) {
    va_list args;
    va_start(args, format);
    if ((LOG_INFO <= active_level) && (active_zones & zone)) {
        LogWithTimestamp(LOG_INFO, zone, format, args);
    }
    va_end(args);
}

void LogDebug(uint32_t zone, const char* format, ...) {
    va_list args;
    va_start(args, format);
    if ((LOG_DEBUG <= active_level) && (active_zones & zone)) {
        LogWithTimestamp(LOG_DEBUG, zone, format, args);
    }
    va_end(args);
}

void SetLevel(LogLevel_t level)
{
    active_level = level;
}

void SetZones(uint32_t zones)
{
    active_zones = zones;
}
