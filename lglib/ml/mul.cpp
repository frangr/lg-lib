#include "mul.h"

MUL::MUL(int num_output, int lun_data):ml(num_output, lun_data, num_output*lun_data, lun_data), posi(0) //la(lb*nd), ip(new bit[la]), lgd(lb)
{
    for(int i = 0; i<lun_data; i++)
        ip[i] = 0;
}

MUL::~MUL() {delete [] ip;}

void MUL::in_process(ldr::bit vc[])
{
    //if(ip)
        //delete [] ip;

    for(int i = 0; i<comple; i++)
        ip[i] = vc[i];
    //ip = vc;
}
void MUL::ln_process(ldr::bit vc[])
{
    posi = data_l * ldr::atn(vc, lane_bit);
}

ldr::bit MUL::m_res(int offst) const {return ip[posi+offst];}
