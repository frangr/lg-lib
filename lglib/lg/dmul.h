#ifndef DMUL_H_INCLUDED
#define DMUL_H_INCLUDED

#include "ldrf.h"

using namespace ldr;

class DMUL
{
public:
    DMUL(int ld, int nl); //lunghezza data, numero linee (output)

    ~DMUL();

    template<typename... T>
    void setin(T&&... ipt); //set input

    template<typename... T>
    void setln(T&&... bc); //set lane

    bit m_res(int offst) const;

private:
    int lip;
    int ipl;
    bit* ip;
    bit* dt;
};

template<typename... T>
void DMUL::setin(T&&... ipt)
{
    bit vc[lip] = {std::forward<bit>(ipt)...};

    for(int i = 0; i<lip; i++)
        dt[i] = vc[i]; //dato da mettere su linea
}

template<typename... T>
void DMUL::setln(T&&... bc)
{
    bit vc[] = {std::forward<bit>(bc)...};

    for(int i = 0; i<ipl; i++)
        ip[i] = 0; //azzera ip

    int offs = atn(vc, sizeof...(bc)) * lip; //control bit per scegliere linea

    for(int i = 0; i<lip; i++)
        ip[i+offs] = dt[i]; //dato messo su linea scelta
}
#endif // DMUL_H_INCLUDED
