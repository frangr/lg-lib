#include "ml.h"

ml::ml(int num_input, int lun_input, int inp_l, int out_l):input_l(inp_l), output_l(out_l),

comple(num_input*lun_input), data_l(lun_input), ip(new ldr::bit[comple]), lane_bit(sqrt(num_input)){}

ml::~ml()
{
    delete [] ip;
}

ldr::bit ml::m_res(int offst) const{}

void ml::in_process(ldr::bit ipt[]){}
void ml::ln_process(ldr::bit ipt[]){}
