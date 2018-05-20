#include "and.h"

AND::AND(int np):gate(np){}

void AND::process(ldr::bit vc[])
{
    rs = 1;

    for(int i=0; i<p; i++)
        if(!vc[i])
        {
            rs = 0;
            break;
        }
}

//bit AND::res() const {return rs;}
