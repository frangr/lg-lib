#include "mul.h"

MUL::MUL(int nd, int lb):la(lb*nd), ip(new bit[la]), lgd(lb){}

MUL::~MUL()
{
    delete [] ip;
}

ldr::bit MUL::m_res(int offst)
{
    return ip[posi+offst];
}
