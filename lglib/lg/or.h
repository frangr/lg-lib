#ifndef OR_H_INCLUDED
#define OR_H_INCLUDED

#include "ldrf.h"

using namespace ldr;

class OR
{
public:
    void inpt(bit a, bit b);
    bit res();
private:
    bit rs = 0;
};

#endif // OR_H_INCLUDED
