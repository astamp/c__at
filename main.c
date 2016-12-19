#include <stdio.h>

#include "cpu.h"
#include "log.h"

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;
    SetLevel(LOG_INFO);
    SetZones(ZONE_ALL);
    LogInfo(ZONE_MAIN, "C/AT version 0.0.1\r\n");
    
    Registers_t regs;
    regs.AX = 0xCAFE;
    printf("regs.AX = 0x%04x\r\n", regs.AX);
    printf("regs.AH = 0x%02x, regs.AL = 0x%02x\r\n", regs.AH, regs.AL);
    return 0;
}
