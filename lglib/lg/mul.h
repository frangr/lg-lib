#ifndef DEC_H_INCLUDED
#define DEC_H_INCLUDED

#include "ldrf.h"

using namespace ldr;

class MUL //multiplexer
{
public:
    MUL(int nd, int lb);

    ~MUL();

    template<typename... T>
    void mulf(T... ipt);

    template<typename... T>
    void muln(T... bc);

    bit m_res(int offst);

private:
    int la = 0;
    bit* ip;
    int posi = 0;
    int lgd = 0;
};

template<typename... T>
void MUL::mulf(T... ipt)
{
    bit vc[la] = {std::forward<bit>(ipt)...};

    for(int i = 0; i<la; i++)
        ip[i] = vc[i];
}

template<typename... T>
void MUL::muln(T... bc)
{
    bit vc[] = {std::forward<bit>(bc)...};

    posi = lgd * atn(vc, sizeof...(bc));
}
#endif // DEC_H_INCLUDED
