#include "CppUTest/TestHarness.h"

#include "cpu.h"
#include <stdio.h>

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
