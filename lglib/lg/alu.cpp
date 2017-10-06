#include "alu.h"

ALU::ALU(int ni, int li):n(ni), l(li) //ni = numero input, li = lunghezza input
{
    rs.resize(li);
}

bit ALU::r_res(int idx)
{
    return rs[(rs.size() - idx) - 1];
    //return rs[idx];
}

bit ALU::getflag(int idx)
{
    return flag[idx];
}
