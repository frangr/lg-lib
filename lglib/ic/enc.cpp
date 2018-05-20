#include "enc.h"
#include<math.h>

ENC::ENC(int li, int no):ic(li)
{
    if(!no) //se il numero di linee output non è specificato
    {
        no = sqrt(li); //numero output corrisponde a radice quadrata di numero input

        if(no % 2 != 0) //se radice quadrate numero input è dispari, aggiunge 1
            no++;
    }

    ip = new ldr::bit[no];

    lo = no; //nl prende il valore di no(non è messo all'inizio per calcolo no)

    for(int i = 0; i<no; i++)
        ip[i] = 0;
}

//ENC::~ENC() {delete [] ip;}

void ENC::process(ldr::bit ipt[])
{
    for(int i = 0; i<ld; i++) //controlla input partendo da MSB
        if(ipt[i]) // il primo bit che trova(quindi l'ultimo nella stringa)
        {
            std::vector<ldr::bit> bt = ldr::nta((ld-i)-1, lo); //numero decimale index trasformato in array

            for(int id = lo-1; id>=0; id--)
                ip[(lo-1)-id] = bt[id]; //index in array messo in array risultato

            break;
        }
}
