#ifndef XNOR_H_INCLUDED
#define XNOR_H_INCLUDED

#include "ldrf.h"

using namespace ldr;

class XNOR
{
public:
    XNOR(int np);

    template<typename... T>
    void inpt(T&&... b);

    bit res();
private:
    int p = 0;
    bit rs = 0;
};

template<typename... T>
void XNOR::inpt(T&&... b)
{
    bit vc[p] = {std::forward<bit>(b)...};
    int n = 0;

    rs = 1;

    for(int i=0; i<p; i++)
    {
        if(vc[i])
            ++n;
    }
    if(n % 2 != 0)
        rs = 0;
}
#endif // XNOR_H_INCLUDED
