#include "negand.h"

NEGAND::NEGAND(int np):gate(np){}

void NEGAND::process(ldr::bit vc[])
{
    rs = 1;

    for(int i=0; i<p; i++)
            if(vc[i])
            {
                rs = 0;
                break;
            }
}
