#ifndef NEGAND_H_INCLUDED
#define NEGAND_H_INCLUDED

#include "ldrf.h"

using namespace ldr;

class NEGAND
{
public:
    NEGAND(int np);

    template<typename... T>
    void inpt(T&&... b);

    bit res();
private:
    int p = 0;
    bit rs = 0;
};

template<typename... T>
void NEGAND::inpt(T&&... b)
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
#endif // NEGAND_H_INCLUDED
