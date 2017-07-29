#ifndef ALU_H_INCLUDED
#define ALU_H_INCLUDED

#include<iostream>
#include<vector>
#include<math.h>
#include "ldrf.h"

using namespace ldr;

//costruttore: lunghezza input, numero input
//aluf: operazione, input
//risultato: vettore risultato, vettore flag
class ALU
{
public:
    ALU(int li, int ni);

    template<typename... T>
    void aluf(bit op1, bit op2, T&&... ipt);//2 bit per decidere operazione + dati da inserire

    bit r_res(int idx);//da il risultato

    bit getflag(int idx);//mostra flag: 0-zero, 1-negative, 2-overflow
private:
    int n, l;
    bit flag[4] = {0, 0, 0, 0}; //alu flag
    std::vector<bit> rs; //sequenza di bit risultante da operazione
};

template<typename... T>
void ALU::aluf(bit op1, bit op2, T&&... ipt)
{
    int sz = l*n, ni = 0;
    size_t res = 0;
    bit bf[sz] = {std::forward<bit>(ipt)...};
    bool bl;
    std::vector<bit> bvec(n);

    int a = n;
    while(a--)
    {
        if(!op1 && !op2) //addizione
            res += ldr::atn(bf, sz, ni, l);
        if(!op1 && op2) //sottrazione
        {
            if(!res)
            {
                res = ldr::atn(bf, sz, ni, l);
            }
            else
            {
                res -= ldr::atn(bf, sz, ni, l);
            }
        }
        if(op1 && !op2) //moltiplicazione
        {
            if(!res)
                res = 1;
            res *= ldr::atn(bf, sz, ni, l);
        }
        if(op1 && op2) //divisione
        {
            if(!bl)
            {
                res = ldr::atn(bf, sz, ni, l);
                bl = true;
            }
            else
                res /= ldr::atn(bf, sz, ni, l);
        }

        ni += l;
    }

    if(!res) //ZERO FLAG
        flag[0] = 1;
    if(res < 0) //NEGATIVE FLAG
    {
        flag[1] = 1;
        res = 0;
    }

    if(res > (pow(2, l))-1) //OVERFLOW FLAG
    {
        flag[2] = 1;
        res = (pow(2, l))-1;

    }

    rs = ldr::nta(res, l);
}

#endif // ALU_H_INCLUDED
