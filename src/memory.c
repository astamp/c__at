#include "memory.h"
#include <stdlib.h>
#include <string.h>

void memory_create(Device_t* dev, size_t size)
{
    MemoryParameters_t* parms;
    dev->mem_write_byte = memory_mem_write_byte;
    dev->mem_read_byte = memory_mem_read_byte;
    dev->parameters = malloc(sizeof(MemoryParameters_t));
    if (NULL != dev->parameters) {
        parms = dev->parameters;
        parms->size = size;
        parms->contents = malloc(size);
        if (NULL != parms->contents) {
            memset(parms->contents, 0, size);
            parms->byte_contents = (uint8_t*)parms->contents;
            parms->word_contents = (uint16_t*)parms->contents;
        }
    }
}

void memory_destroy(Device_t* dev)
{
    if ((NULL != dev) && (NULL != dev->parameters)) {
        MemoryParameters_t* parms = dev->parameters;
        if (NULL != parms->contents) {
            free(parms->contents);
        }
        free(dev->parameters);
        dev->parameters = NULL;
    }
}

void memory_mem_write_byte(Device_t* dev, size_t offset, uint8_t value)
{
    if ((NULL != dev) && (NULL != dev->parameters)) {
        MemoryParameters_t* parms = dev->parameters;
        parms->byte_contents[offset] = value;
    }
}

uint8_t memory_mem_read_byte(Device_t* dev, size_t offset)
{
    uint8_t value = 0;
    if ((NULL != dev) && (NULL != dev->parameters)) {
        MemoryParameters_t* parms = dev->parameters;
        value = parms->byte_contents[offset];
    }
    return value;
}
