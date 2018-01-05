#ifndef OR_H_INCLUDED
#define OR_H_INCLUDED

#include "ldrf.h"

using namespace ldr;

class OR
{
public:
    OR(int np);

    template<typename... T>
    void inpt(T&&... b);

    bit res() const;
private:
    int p;
    bit rs = 0;
};

template<typename... T>
void OR::inpt(T&&... b)
{
    bit vc[p] = {std::forward<bit>(b)...};
    bool bb = false;

    rs = 0;

    for(int i=0; !bb; i++)
    {
        if(i<p)
        {
            if(vc[i])
            {
                rs = 1;
                bb = true;
            }
        }
        else
            bb = true;
    }
}

#endif // OR_H_INCLUDED
