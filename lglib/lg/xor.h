#ifndef XOR_H_INCLUDED
#define XOR_H_INCLUDED

#include "ldrf.h"
#include<iostream>

using namespace ldr;

class XOR
{
public:
    XOR(int np);

    template<typename... T>
    void inpt(T&&... b);

    bit res();
private:
    int p = 0;
    bit rs = 0;
};

template<typename... T>
void XOR::inpt(T&&... b)
{
    bit vc[p] = {std::forward<bit>(b)...};
    int n = 0;

    rs = 0;

    for(int i=0; i<p; i++)
    {
        if(vc[i])
            ++n;
    }
    if(n % 2 != 0)
        rs = 1;
}
#endif // XOR_H_INCLUDED
