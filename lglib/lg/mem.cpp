#include "mem.h"
#include<math.h>

MEM::MEM(int siz, int dat):sz(dat)
{
    int pw = pow(2, siz);
    v1 = new bit[pw*dat];
    rs = new bit[dat];
    wd = new bit[dat];
}

bit MEM::res(int idx)
{
    return rs[idx];
}
