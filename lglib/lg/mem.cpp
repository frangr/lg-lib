#include "mem.h"
#include<math.h>

MEM::MEM(int siz, int dat):sz(dat)
{
    int pw = pow(2, siz);
    v1.resize(pw*dat);
    rs.resize(dat);
    wd.resize(dat);
}

bit MEM::res(int idx)
{
    return rs[idx];
}
