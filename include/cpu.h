#ifndef __CPU_H__
#define __CPU_H__

#include <stdint.h>

typedef struct {
    /* Base Registers */
    union {
        struct {
            uint8_t AL;
            uint8_t AH;
            uint8_t BL;
            uint8_t BH;
            uint8_t CL;
            uint8_t CH;
            uint8_t DL;
            uint8_t DH;
        };
        struct {
            uint16_t AX;
            uint16_t BX;
            uint16_t CX;
            uint16_t DX;
        };
    };
    
    /* Index Registers */
    uint16_t SI;
    uint16_t DI;
    
    /* Pointers */
    uint16_t IP;
    uint16_t SP;
    uint16_t BP;
    
    /* Segment Registers. */
    uint16_t CS;
    uint16_t DS;
    uint16_t ES;
    uint16_t SS;
} Registers_t;

void cpu_initialize_registers(Registers_t* regs);

#endif // __CPU_H__
