#include "or.h"

OR::OR(int np):gate(np){}

void OR::process(ldr::bit vc[])
{
    rs = 0;

    for(int i=0; i<p; i++)
            if(vc[i])
            {
                rs = 1;
                break;
            }
}
