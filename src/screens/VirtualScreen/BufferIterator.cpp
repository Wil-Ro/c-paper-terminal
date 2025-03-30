#include "BufferIterator.h"

BufferIterator::BufferIterator(UBYTE* buffer, int bufferLength)
{
    bytePointer = 0;
    interBytePointer = 0;
    this->buffer = buffer;
    this->bufferLength = bufferLength;
}

bool BufferIterator::next()
{
    if (bytePointer >= this->bufferLength)
    {
        //fprintf(stderr, "Warning! BufferIterator reached the end of a buffer and is now just returning false\n");
        return false;
    }

    bool bitState = (buffer[bytePointer] & (128 >> interBytePointer));

    interBytePointer++;
    if (interBytePointer >= 8)
    {
        interBytePointer = 0;
        bytePointer++;
    }

    return bitState;
}
