#ifndef LDRF_H_INCLUDED
#define LDRF_H_INCLUDED

#include<iostream>
#include<vector>

namespace ldr
{
    using bit = bool; //bit

    bit notf(bit bt); //funzione di negazione


    template<typename... T>
    size_t btn(T... n); //bit a decimale

    size_t atn(bit vc[], int sz, int spos=0, int idx=0); //array di bit a decimale

    std::vector<bit> nta(size_t n, int vs = 0); //numero a array
}

template<typename... T>
size_t ldr::btn(T... n)
{
    int s = sizeof...(T);
    size_t bn = 0, pn = 1;
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
