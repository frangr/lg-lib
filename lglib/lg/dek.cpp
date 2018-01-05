#include "dek.h"
#include<math.h>

//DEC::DEC(int nd, int lb):la(lb*nd), ip(new bit[la]), lgd(lb)
DEC::DEC(int li, int no):ld(li)
{
    if(!no)
        no = pow(2, li);

    ip = new bit[no];

    /*
    for(int i = 0; i<no; i++)
        ip[i] = 0;
    */
}

DEC::~DEC() {delete [] ip;}

bit DEC::d_res(int offst) const {return ip[offst];}
