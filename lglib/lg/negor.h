#ifndef NEGOR_H_INCLUDED
#define NEGOR_H_INCLUDED

#include "ldrf.h"
#include<iostream>

using namespace ldr;

class NEGOR
{
public:
    NEGOR(int np);

    template<typename... T>
    void inpt(T&&... b);

    bit res();
private:
    int p = 0;
    bit rs = 0;
};

template<typename... T>
void NEGOR::inpt(T&&... b)
{
    bool bb = false;
    bit vc[p] = {std::forward<bit>(b)...};

    rs = 0;

    for(int i=0; !bb; i++)
    {
        if(i<p)
        {
            if(!vc[i])
            {
                rs = 1;
                bb = true;
            }
        }
        else
            bb = true;
    }
}
#endif // NEGOR_H_INCLUDED
