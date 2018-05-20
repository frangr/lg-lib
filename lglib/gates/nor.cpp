#include "nor.h"

NOR::NOR(int np):gate(np){}

void NOR::process(ldr::bit vc[])
{
    rs = 1;

    for(int i=0; i<p; i++)
            if(vc[i])
            {
                rs = 0;
                break;
            }
}
