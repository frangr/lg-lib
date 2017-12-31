#include "dmul.h"

DMUL::DMUL(int ld, int nl):lip(ld)
{
    ipl = ld*nl;

    ip = new bit[ipl];

    dt = new bit[ld];

    /*
    for(int i = 0; i<ipl; i++)
        ip[i] = 0;
    */

}

DMUL::~DMUL()
{
    delete [] ip;
    delete [] dt;
}

bit DMUL::m_res(int offst)
{
    return ip[offst];
}
