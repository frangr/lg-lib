#ifndef MEM_H_INCLUDED
#define MEM_H_INCLUDED

#include "ldrf.h"
#include<vector>

using namespace ldr;

class MEM
{
public:
    MEM(int siz, int dat); //numero dati e loro lunghezza

    template<typename... T>
    void memf(bit fl, T&&... adr); //flag lettura/scrittura e indirizzo

    template<typename... T>
    void setwd(T&&... wdt); //dati da scrivere

    bit res(int idx); //parola letta
private:
    std::vector<bit> v1; //vettore contenente dati
    int sz = 0;
    std::vector<bit> rs; //vettore risultato
    std::vector<bit> wd; //write data
};

template<typename... T>
void MEM::memf(bit fl, T&&... adr)//, T&&... wdat)
{
    int ar = ldr::btn(adr...);

    if(fl) //write
    {
        for(int i=0; i<sz; i++)
            v1[ar+i] = wd[i];
    }
    else //read
    {
        for(int i=0; i<sz; i++)
            rs[i] = v1[ar+i];
    }
}

template<typename... T>
void MEM::setwd(T&&... wdt)
{
    wd = {std::forward<bit>(wdt)...};
}

#endif // MEM_H_INCLUDED
