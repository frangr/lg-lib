#ifndef ENC_H_INCLUDED
#define ENC_H_INCLUDED

#include "ldrf.h"

using namespace ldr;

class ENC
{
public:
    ENC(int li, int no = 0);

    ~ENC();

    template<typename... T>
    void setin(T&&... ipt); //set input

    bit e_res(int offst) const;

private:
    int ld;
    int nl;
    bit* ip;
};

template<typename... T>
void ENC::setin(T&&... ipt)
{
    bit vc[ld] = {std::forward<bit>(ipt)...};

    bool c = false;

    for(int i = 0; i<ld && !c; i++) //controlla input partendo da MSB
    {
        if(vc[i]) // il primo bit che trova(quindi l'ultimo nella stringa)
        {
            std::vector<bit> bt = nta((ld-i)-1, nl); //numero decimale index trasformato in array

            for(int id = nl-1; id>=0; id--)
                ip[(nl-1)-id] = bt[id]; //index in array messo in array risultato

            c = true; // ferma il ciclo
        }
    }
}
#endif // ENC_H_INCLUDED
