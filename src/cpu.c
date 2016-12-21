#include "cpu.h"
#include <string.h>

void cpu_initialize_registers(Registers_t* regs)
{
    if (NULL != regs) {
        memset(regs, 0, sizeof(Registers_t));
        regs->CS = 0xFFFF;
    }
}
