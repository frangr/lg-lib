#include "xor.h"

XOR::XOR(int np):gate(np){}

void XOR::process(ldr::bit vc[])
{
    int n = 0;

    rs = 0;

    for(int i=0; i<p; i++)
        if(vc[i])
            ++n;

    if(n % 2 != 0)
        rs = 1;
}
