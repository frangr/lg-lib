#include "xnor.h"

XNOR::XNOR(int np):gate(np){}

void XNOR::process(ldr::bit vc[])
{
    int n = 0;
    rs = 1;

    for(int i=0; i<p; i++)
        if(vc[i])
            ++n;

    if(n % 2 != 0)
        rs = 0;
}
