#include "dek.h"
#include<math.h>

//DEC::DEC(int nd, int lb):la(lb*nd), ip(new bit[la]), lgd(lb)
DEC::DEC(int li, int no):ic(li)
{
    if(!no)
        no = pow(2, li);

    ip = new ldr::bit[no];
}

void DEC::process(ldr::bit ipt[])
{
    ip[lo] = 0;

    lo = ldr::atn(ipt, ld);//sizeof...(ipt));

    ip[lo] = 1;
}
