#include "ic.h"

ic::ic(int li):ld(li), lo(0){}

ldr::bit ic::res(int idx) const {return ip[idx];}

ic::~ic()
{
    delete [] ip;
}

void ic::process(ldr::bit ipt[]){}
