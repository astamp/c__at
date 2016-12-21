#include "CppUTest/TestHarness.h"

extern "C" {
    #include "cpu.h"
}

TEST_GROUP(Registers_tTests)
{

};

TEST(Registers_tTests, ax_linked_to_ah_al)
{
    Registers_t regs;
    regs.AX = 0xCAFE;
    LONGS_EQUAL(0xCA, regs.AH);
    LONGS_EQUAL(0xFE, regs.AL);

    regs.AH = 0x12;
    LONGS_EQUAL(0x12FE, regs.AX);
    regs.AL = 0x34;
    LONGS_EQUAL(0x1234, regs.AX);
}

TEST(Registers_tTests, bx_linked_to_bh_bl)
{
    Registers_t regs;
    regs.BX = 0xCAFE;
    LONGS_EQUAL(0xCA, regs.BH);
    LONGS_EQUAL(0xFE, regs.BL);

    regs.BH = 0x12;
    LONGS_EQUAL(0x12FE, regs.BX);
    regs.BL = 0x34;
    LONGS_EQUAL(0x1234, regs.BX);
}

TEST(Registers_tTests, cx_linked_to_ch_cl)
{
    Registers_t regs;
    regs.CX = 0xCAFE;
    LONGS_EQUAL(0xCA, regs.CH);
    LONGS_EQUAL(0xFE, regs.CL);

    regs.CH = 0x12;
    LONGS_EQUAL(0x12FE, regs.CX);
    regs.CL = 0x34;
    LONGS_EQUAL(0x1234, regs.CX);
}

TEST(Registers_tTests, dx_linked_to_dh_dl)
{
    Registers_t regs;
    regs.DX = 0xCAFE;
    LONGS_EQUAL(0xCA, regs.DH);
    LONGS_EQUAL(0xFE, regs.DL);

    regs.DH = 0x12;
    LONGS_EQUAL(0x12FE, regs.DX);
    regs.DL = 0x34;
    LONGS_EQUAL(0x1234, regs.DX);
}

TEST(Registers_tTests, 16_bit_overflow)
{
    Registers_t regs;
    regs.AX = 0xFFFF;
    regs.AX += 1;
    LONGS_EQUAL(0, regs.AX);
}

TEST(Registers_tTests, 16_bit_underflow)
{
    Registers_t regs;
    regs.AX = 0;
    regs.AX -= 1;
    LONGS_EQUAL(0xFFFF, regs.AX);
}

TEST(Registers_tTests, 8_bit_overflow_high)
{
    Registers_t regs;
    regs.AX = 0;
    regs.AH = 0xFF;
    regs.AH += 1;
    LONGS_EQUAL(0, regs.AH);
    LONGS_EQUAL(0, regs.AX);
}

TEST(Registers_tTests, 8_bit_overflow_low)
{
    Registers_t regs;
    regs.AX = 0;
    regs.AL = 0xFF;
    regs.AL += 1;
    LONGS_EQUAL(0, regs.AL);
    LONGS_EQUAL(0, regs.AX);
}

TEST(Registers_tTests, 8_bit_underflow_high)
{
    Registers_t regs;
    regs.AX = 0;
    regs.AH -= 1;
    LONGS_EQUAL(0xFF, regs.AH);
    LONGS_EQUAL(0xFF00, regs.AX);
}

TEST(Registers_tTests, 8_bit_underflow_low)
{
    Registers_t regs;
    regs.AX = 0;
    regs.AL -= 1;
    LONGS_EQUAL(0xFF, regs.AL);
    LONGS_EQUAL(0x00FF, regs.AX);
}

TEST(Registers_tTests, assignment_masks_to_8_bits)
{
    Registers_t regs;
    regs.AX = 0;

// Intentionally testing the overflow condition.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverflow"
    regs.AL = 384;
#pragma GCC diagnostic pop
    LONGS_EQUAL(128, regs.AL);
    LONGS_EQUAL(0, regs.AH);
}

TEST(Registers_tTests, assignment_masks_to_16_bits)
{
    Registers_t regs;

// Intentionally testing the overflow condition.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverflow"
    regs.AX = 115200;
#pragma GCC diagnostic pop
    LONGS_EQUAL(49664, regs.AX);
}

TEST(Registers_tTests, cpu_initialize_registers)
{
    Registers_t regs;
    cpu_initialize_registers(&regs);
    LONGS_EQUAL(0, regs.AX);
    LONGS_EQUAL(0, regs.BX);
    LONGS_EQUAL(0, regs.CX);
    LONGS_EQUAL(0, regs.DX);
    LONGS_EQUAL(0, regs.IP);
    LONGS_EQUAL(0, regs.BP);
    LONGS_EQUAL(0, regs.SI);
    LONGS_EQUAL(0, regs.DI);
    LONGS_EQUAL(0xFFFF, regs.CS);
    LONGS_EQUAL(0, regs.DS);
    LONGS_EQUAL(0, regs.ES);
    LONGS_EQUAL(0, regs.SS);
}

TEST(Registers_tTests, cpu_initialize_registers_null)
{
    cpu_initialize_registers(NULL);
}

