#include "enc.h"
#include<math.h>

ENC::ENC(int li, int no):ld(li)
{
    if(!no) //se il numero di linee output non è specificato
    {
        no = sqrt(li); //numero output corrisponde a radice quadrata di numero input

        if(no % 2 != 0) //se radice quadrate numero input è dispari, aggiunge 1
            no++;
    }

    ip = new bit[no];

    nl = no; //nl prende il valore di no(non è messo all'inizio per calcolo no)

    for(int i = 0; i<no; i++)
        ip[i] = 0;
}

ENC::~ENC()
{
    delete [] ip;
}

bit ENC::e_res(int offst)
{
    return ip[offst];
}
