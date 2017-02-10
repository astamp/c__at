#ifndef __BUS_H__
#define __BUS_H__

#include <stdint.h>
#include <stddef.h>

typedef struct Device Device_t;

typedef void(*InstallHandler_t)(struct SystemBus* bus);
typedef void(*ClockHandler_t)(void);
typedef uint8_t(*ReadByteHandler_t)(Device_t* device, size_t offset);
typedef uint16_t(*ReadWordHandler_t)(size_t offset);
typedef void(*WriteByteHandler_t)(Device_t* device, size_t offset, uint8_t value);
typedef void(*WriteWordHandler_t)(size_t offset, uint16_t value);
typedef size_t(*GetPortsListHandler_t)(uint16_t* buffer, size_t buffer_length);

struct Device {
    InstallHandler_t install;
    ClockHandler_t clock;

    ReadByteHandler_t mem_read_byte;
    ReadWordHandler_t mem_read_word;
    WriteByteHandler_t mem_write_byte;
    WriteWordHandler_t mem_write_word;

    GetPortsListHandler_t get_ports_list;
    ReadByteHandler_t io_read_byte;
    ReadWordHandler_t io_read_word;
    WriteByteHandler_t io_write_byte;
    WriteWordHandler_t io_write_word;

    void* parameters;
};

#endif // __BUS_H__
