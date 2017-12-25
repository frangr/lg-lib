#include "mul.h"

MUL::MUL(int nd, int lb):la(lb*nd), ip(new bit[la]), lgd(lb)
{
    for(int i = 0; i<la; i++)
        ip[i] = 0;
}

MUL::~MUL()
{
    delete [] ip;
}

ldr::bit MUL::m_res(int offst)
{
    return ip[posi+offst];
}
