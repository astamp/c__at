#include "CppUTest/TestHarness.h"

extern "C" {
    #include "cpu.h"
}

TEST_GROUP(Flags_tTests)
{
    Flags_t flags;

    void setup()
    {
        flags.value = 0;
    }
};

TEST(Flags_tTests, test_carry_flag_property_get)
{
    LONGS_EQUAL(0, flags.carry);
    flags.value |= FLAGS_CARRY;
    LONGS_EQUAL(1, flags.carry);
}

TEST(Flags_tTests, test_carry_flag_property_set)
{
    LONGS_EQUAL(0, flags.value);
    flags.carry = 1;
    LONGS_EQUAL(FLAGS_CARRY, flags.value);
    flags.carry = 0;
    LONGS_EQUAL(0, flags.value);
}

TEST(Flags_tTests, test_parity_flag_property_get)
{
    LONGS_EQUAL(0, flags.parity);
    flags.value |= FLAGS_PARITY;
    LONGS_EQUAL(1, flags.parity);
}

TEST(Flags_tTests, test_parity_flag_property_set)
{
    LONGS_EQUAL(0, flags.value);
    flags.parity = 1;
    LONGS_EQUAL(FLAGS_PARITY, flags.value);
    flags.parity = 0;
    LONGS_EQUAL(0, flags.value);
}
