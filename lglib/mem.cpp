#include "mem.h"
#include<math.h>

MEM::MEM(int siz, int dat):sz(dat), rs(new ldr::bit[dat]), wd(new ldr::bit[dat])
{
    int pw = pow(2, siz);
    v1 = new ldr::bit[pw*dat];

    for(int i = 0; i<dat; i++)
    {
        v1[i] = 0;
        rs[i] = 0;
        wd[i] = 0;
    }

}

MEM::~MEM()
{
    delete [] v1;
    delete [] rs;
    delete [] wd;
}

void MEM::set_rw(ldr::bit rwf) {fl = rwf;}

ldr::bit MEM::res(int idx) const {return rs[idx];}
