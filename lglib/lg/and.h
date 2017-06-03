#ifndef AND_H_INCLUDED
#define AND_H_INCLUDED

#include "ldrf.h"
#include<iostream>

using namespace ldr;

class AND
{
public:
    AND(int np);

    template<typename... T>
    void inpt(T... b);

    bit res();
private:
    int p = 0;
    bit rs = 0;
};

template<typename... T>
void AND::inpt(T... b)
{
    bool bb = false;
    bit vc[p] = {std::forward<bit>(b)...};

    rs = 1;

    for(int i=0; !bb; i++)
    {
        if(i<p)
        {
            if(!vc[i])
            {
                rs = 0;
                bb = true;
            }
        }
        else
        {
            bb = true;
        }
    }
}
#endif // AND_H_INCLUDED
