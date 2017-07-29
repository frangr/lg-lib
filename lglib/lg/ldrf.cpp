#include "ldrf.h"

ldr::bit ldr::NOT(bit bt)
{
    return bt-1;
}

size_t ldr::atn(bit vc[], int sz, int spos, int idx)
{
    int s;
    size_t bn = 0, pn = 1;

    if(spos == 0 && idx == 0)
    {
        s = sz;
    }
    else
    {
        s = idx;
    }

    while(s--)
    {
        if(vc[spos+s])
            bn += pn;
        pn += pn;
    }
    return bn;
}

std::vector<ldr::bit> ldr::nta(size_t n, int vs)
{
    int nu = 1, ct = 0, ctb = 0;
    bool vb;
    std::vector<bit> nt;

    while(n)
    {
        if(!vb)
            nt.emplace_back(0);

        ctb++;

        if(nu <= n && nu >= (n/2)+1)
        {
            n -= nu;
            nu = 1;
            nt[ct] = 1;
            ctb = 0;
            vb = true;
        }
        else
        {
            nu += nu;
        }
        ct = ctb;
    }

    if(vs)
        nt.resize(vs);

    return nt;
}
