#ifndef DEK_H_INCLUDED
#define DEK_H_INCLUDED

#include "ldrf.h"

using namespace ldr;

class DEC
{
public:
    DEC(int li, int no = 0); //lunghezza input, numero output(se no=0 allora no=2^li)

    ~DEC();

    template<typename... T>
    void setin(T&&... ipt); //set input

    bit d_res(int offst) const;

private:
    int ld, lo = 0;
    bit* ip;
};

template<typename... T>
void DEC::setin(T&&... ipt)
{
    bit vc[ld] = {std::forward<bit>(ipt)...};

    ip[lo] = 0;

    lo = atn(vc, sizeof...(ipt));

    ip[lo] = 1;
}
#endif // DEK_H_INCLUDED
