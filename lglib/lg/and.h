#ifndef AND_H_INCLUDED
#define AND_H_INCLUDED

#include "ldrf.h"

using namespace ldr;

class AND
{
public:
    void inpt(bit a, bit b);
    bit res();
private:
    bit rs = 0;
};

#endif // AND_H_INCLUDED
