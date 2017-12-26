#ifndef ALU_H_INCLUDED
#define ALU_H_INCLUDED

#include "ldrf.h"

using namespace ldr;

//costruttore: lunghezza input
//aluf: operazione, input
//risultato: vettore risultato, vettore flag
class ALU
{
public:
    ALU(int li);

    ~ALU();

    void set_op(bit ope1, bit ope2);

    template<typename... T>
    void aluf(T&&... ipt);

    bit r_res(int idx);

    bit getflag(int idx);


private:

    void add(bit bf[]);
    void uadd(bit bf[]);

    void sub(bit bf[]);
    void usub(bit bf[]);

    int l;
    bit flag[4] = {}; //alu flag: 0-zero flag, 1-negative flag, 2-overflow flag, 3-division by zero flag
    bit* rs;
    bit op1 = 0, op2 = 0;
};

template<typename... T>
void ALU::aluf(T&&... ipt)
{
    bit bf[l*2] = {std::forward<bit>(ipt)...};

    for(int i = 0; i<l; i++)
        rs[i] = 0;

    if(!op1 && !op2) //addizione
    {
        add(bf);
    }

    if(!op1 && op2) //sottrazione
    {
        sub(bf);
    }

    if(op1 && !op2) //moltiplicazione
    {
        int zca = 0, zcb = 0; //conta degli zeri

        flag[0] = 1;

        bool cp = false, cs = false;

        for(int i = (l*2)-1; i>=l && !cp; i--)
        {
            if(bf[i] == 1) //se viene trovato un 1 in B, moltiplicatore
            {
                zca = 0;

                for(int id = l-1; id>=0 && !cs; id--) //viene cercato un 1 anche in A, moltiplicando
                {
                    if(bf[id] == 1) //se viene trovato
                    {
                        if(zca+zcb >= l)
                        {
                            flag[2] = 1;
                            cs = true;
                            cp = true;
                        }
                        bit trb[l] = {};
                        trb[(l-1)-(zca+zcb)] = 1; //crea array da sommare
                        uadd(trb);
                    }
                    zca++;
                }
            }
            zcb++; //conta gli zeri prima di 1 in B
        }
    }

    if(op1 && op2) //divisione
    {
        int cnt = 0;

        bit divb[l] = {};

        flag[3] = 1;

        for(int i = l-1; i>=0; i--)
        {
            int id = l+i;

            if(bf[id] == 1) //se nel divisore c'è un 1
            {
                flag[3] = 0;
            }

            rs[i] = bf[i]; //a rs viene assegnato primo operando
            divb[i] = bf[id];
        }

        if(!flag[3])
        {
            while(flag[0] == 0 && flag[1] == 0)
            {
                usub(divb);
                cnt++;
            }

            if(flag[1] == 1)
            {
                cnt--; //se c'è resto, risultato viene scalato di 1
                flag[1] = 0;
            }

            for(int i = 0; i<l; i++)
            {
                rs[i] = 0;
            }

            if(cnt)
            {
                bit rsi[l] = {};
                rsi[l-1] = 1;

                while(cnt--)
                {
                    uadd(rsi);
                }
            }
            else
            {
                flag[0] = 1; //se cnt è 0 e non aggiunge nessun 1 allora risultato divisione è 0 e setta flag
            }
        }
    }
}
#endif // ALU_H_INCLUDED
