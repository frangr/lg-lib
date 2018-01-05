#include "dmul.h"

DMUL::DMUL(int ld, int nl):lip(ld), ipl(ld*nl), ip(new bit[ipl]), dt(new bit[ld]){}

DMUL::~DMUL()
{
    delete [] ip;
    delete [] dt;
}

bit DMUL::m_res(int offst) const {return ip[offst];}
