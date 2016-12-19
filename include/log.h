#ifndef __LOG_H__
#define __LOG_H__

#include <stdint.h>

#define ZONE_MAIN   (0x00000001u)
#define ZONE_CPU    (0x00000002u)
#define ZONE_ALL    (0xFFFFFFFFu)

typedef enum {
    LOG_ERROR,
    LOG_INFO,
    LOG_DEBUG,
} LogLevel_t;

void LogError(const char* format, ...);
void LogInfo(uint32_t zone, const char* format, ...);
void LogDebug(uint32_t zone, const char* format, ...);

void SetLevel(LogLevel_t level);
void SetZones(uint32_t zone);

#endif // __LOG_H__