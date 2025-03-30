#include "../../Structs.h"
#include <stdio.h>
#include <iostream>

class BufferIterator
{


public:
    bool next();
    BufferIterator(UBYTE* buffer, int bufferLength);

private:
    int bytePointer;
    int interBytePointer;
    UBYTE* buffer;
    int bufferLength;

};
