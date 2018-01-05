#include "mul.h"

MUL::MUL(int nd, int lb):la(lb*nd), ip(new bit[la]), lgd(lb)
{
    for(int i = 0; i<la; i++)
        ip[i] = 0;
}

MUL::~MUL() {delete [] ip;}

bit MUL::m_res(int offst) const {return ip[posi+offst];}
