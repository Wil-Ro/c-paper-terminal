#include <catch2/catch_test_macros.hpp>
#include "../../../src/screens/VirtualScreen/BufferIterator.h"

TEST_CASE("BufferIterator correctly steps through byte") {
    UBYTE buffer = 0b00001111;
    BufferIterator* iter = new BufferIterator(&buffer, 0);

    int results[8] = {0, 0, 0, 0, 1, 1, 1, 1};

    for (int i=0; i<8; i++)
    {
        REQUIRE(iter->next() == results[i]);
    }
}

TEST_CASE("BufferIterator correctly steps up a byte") {
    UBYTE buffer[2] = {0b00001111, 0b00001111};
    BufferIterator* iter = new BufferIterator(buffer,0 );

    int results[8] = {0, 0, 0, 0, 1, 1, 1, 1};

    for (int i=0; i<8; i++)
    {
        iter->next();
    }

    for (int i=0; i<8; i++)
    {
        REQUIRE(iter->next() == results[i]);
    }

}
