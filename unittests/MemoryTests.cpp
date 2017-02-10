#include "CppUTest/TestHarness.h"

extern "C" {
    #include "memory.h"
}

TEST_GROUP(MemoryTests)
{
    Device_t ram;
    MemoryParameters_t* parms;

    void setup()
    {
        memory_create(&ram, 64);
        parms = (MemoryParameters_t*)ram.parameters;
    }

    void teardown()
    {
        memory_destroy(&ram);
        parms = NULL;
    }
};

TEST(MemoryTests, test_size_filled_in)
{
    LONGS_EQUAL(64, parms->size);
}

TEST(MemoryTests, test_initialized_to_zero)
{
    size_t x;
    for(x = 0; x < 64; x++) {
        LONGS_EQUAL(0, parms->byte_contents[x]);
    }
}

TEST(MemoryTests, test_all_pointers_equal)
{
    CHECK(NULL != parms->contents);
    CHECK(parms->contents == parms->byte_contents);
    CHECK(parms->contents == parms->word_contents);
}

TEST(MemoryTests, test_write_byte)
{
    ram.mem_write_byte(&ram, 56, 43);
    LONGS_EQUAL(43, parms->byte_contents[56]);
}

TEST(MemoryTests, test_read_byte)
{
    parms->byte_contents[21] = 76;
    parms->byte_contents[22] = 77;
    parms->byte_contents[23] = 78;
    LONGS_EQUAL(77, ram.mem_read_byte(&ram, 22));
}
