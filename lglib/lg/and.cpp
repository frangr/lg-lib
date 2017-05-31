#include "and.h"

void AND::inpt(bit a, bit b)
{
    rs = a*b;
}

bit AND::res()
{
    return rs;
}
