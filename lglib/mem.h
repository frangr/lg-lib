#ifndef MEM_H_INCLUDED
#define MEM_H_INCLUDED

#include "ldrf.h"

class MEM
{
public:
    MEM(int siz, int dat); //numero dati e loro lunghezza

    ~MEM();

    void set_rw(ldr::bit rwf);

    template<typename... T>
    void memf(T&&... adr); //flag lettura/scrittura e indirizzo

    template<typename... T>
    void setwd(T&&... wdt); //dati da scrivere

    ldr::bit res(int idx) const; //parola letta
private:
    ldr::bit* v1; //puntatore array dati
    int sz;
    ldr::bit* rs; //puntatore array risultato
    ldr::bit* wd; //write data
    ldr::bit fl = 0; //read/write flag
};

template<typename... T>
void MEM::memf(T&&... adr)//, T&&... wdat)
{
    int ar = ldr::btn(adr...);

    if(fl) //write
    {
        for(int i=0; i<sz; i++)
            v1[(ar*sz)+i] = wd[i];
    }
    else //read
    {
        for(int i=0; i<sz; i++)
            rs[i] = v1[(ar*sz)+i];
    }
}

template<typename... T>
void MEM::setwd(T&&... wdt)
{
    ldr::bit bf[sz] = {std::forward<ldr::bit>(wdt)...};

    for(int i=0; i<sz; i++)
        wd[i] = bf[i];
}

#endif // MEM_H_INCLUDED
