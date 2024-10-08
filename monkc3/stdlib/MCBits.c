#include "MCBits.h"

MCBits MCBitsMask(unsigned bitIndex)
{
    return (0x01 << bitIndex);
}

bool MCBitsIsSetAt(MCBits bits, unsigned bitIndex)
{
    if (bits & MCBitsMask(bitIndex)) {
        return true;
    }
    return false;
}

unsigned MCBitsSetBitNum(MCBits bits) {
    MCBits mask = 0x01;
    unsigned bitsCount = sizeof(MCBits) * 8;
    
    unsigned i, count=0;
    for(i=0; i<bitsCount; i++) {
        if((bits & mask) != 0)
            count++;
        mask <<= 1;
    }
    
    return count;
}

MCBits MCBitsXORFindOddInPairs(const MCBits* pairs, size_t count) {
    MCBits xor = 0;
    int i;
    for (i=0; i<count; i++) {
        xor = xor^pairs[i];
    }
    return xor;
}
