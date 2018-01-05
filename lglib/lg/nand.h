#ifndef NAND_H_INCLUDED
#define NAND_H_INCLUDED

#include "ldrf.h"

using namespace ldr;

class NAND
{
public:
    NAND(int np);

    template<typename... T>
    void inpt(T&&... b);

    bit res() const;
private:
    int p;
    bit rs = 0;
};

template<typename... T>
void NAND::inpt(T&&... b)
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
#endif // NAND_H_INCLUDED
