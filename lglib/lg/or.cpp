#include "or.h"

void OR::inpt(bit a, bit b)
{
    rs = a+b;
}

bit OR::res()
{
    return rs;
}
