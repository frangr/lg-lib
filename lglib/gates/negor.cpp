#include "negor.h"

NEGOR::NEGOR(int np):gate(np){}

void NEGOR::process(ldr::bit vc[])
{
    rs = 0;

    for(int i=0; i<p; i++)
            if(!vc[i])
            {
                rs = 1;
                break;
            }
}
