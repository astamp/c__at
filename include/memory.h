#ifndef __MEMORY_H__
#define __MEMORY_H__

#include "bus.h"

typedef struct {
    void* contents;
    uint8_t* byte_contents;
    uint16_t* word_contents;
    size_t size;
} MemoryParameters_t;

void memory_create(Device_t* device, size_t size);
void memory_destroy(Device_t* device);
void memory_mem_write_byte(Device_t* device, size_t offset, uint8_t value);
uint8_t memory_mem_read_byte(Device_t* device, size_t offset);

#endif // __MEMORY_H__
