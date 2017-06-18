#ifndef LDRF_H_INCLUDED
#define LDRF_H_INCLUDED

#include<iostream>

namespace ldr
{
    using bit = bool;

    bit NOT(bit bt);


    template<typename... T>
    int btn(T&&... n);
}

template<typename... T>
int ldr::btn(T&&... n)
{
    int s = sizeof...(T), pn = 1, bn = 0;
    bit vc[s] = {std::forward<bit>(n)...};

    while(s--)
    {
        if(vc[s])
            bn += pn;
        pn += pn;
    }
    return bn;
}

#endif // LDRF_H_INCLUDED
