#ifndef NOR_H_INCLUDED
#define NOR_H_INCLUDED

#include "ldrf.h"

using namespace ldr;

class NOR
{
public:
    NOR(int np);

    template<typename... T>
    void inpt(T&&... b);

    bit res() const;
private:
    int p;
    bit rs = 0;
};

template<typename... T>
void NOR::inpt(T&&... b)
{
    bool bb = false;
    bit vc[p] = {std::forward<bit>(b)...};

    rs = 1;

    for(int i=0; !bb; i++)
    {
        if(i<p)
        {
            if(vc[i])
            {
                rs = 0;
                bb = true;
            }
        }
        else
            bb = true;
    }
}
#endif // NOR_H_INCLUDED
