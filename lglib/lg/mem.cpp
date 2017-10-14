#include "mem.h"
#include<math.h>

MEM::MEM(int siz, int dat):sz(dat), rs(new bit[dat]), wd(new bit[dat])
{
    int pw = pow(2, siz);
    v1 = new bit[pw*dat];
}

MEM::~MEM()
{
    delete [] v1;
    delete [] rs;
    delete [] wd;
}

bit MEM::res(int idx)
{
    return rs[idx];
}
