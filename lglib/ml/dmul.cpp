#include "dmul.h"

DMUL::DMUL(int num_output, int lun_data):ml(num_output, lun_data, lun_data, num_output*lun_data),
dt(new ldr::bit[lun_data]){}
//lunghezza data, numero linee

DMUL::~DMUL()
{
    delete [] dt;
}

void DMUL::in_process(ldr::bit vc[])
{
    for(int i = 0; i<data_l; i++)
        dt[i] = vc[i];
}
void DMUL::ln_process(ldr::bit vc[])
{
    for(int i = 0; i<comple; i++)
        ip[i] = 0; //azzera ip

    int offs = ldr::atn(vc, lane_bit) * data_l; //control bit per scegliere linea

    for(int i = 0; i<data_l; i++)
        ip[i+offs] = dt[i]; //dato messo su linea scelta
}

ldr::bit DMUL::m_res(int offst) const {return ip[offst];}
