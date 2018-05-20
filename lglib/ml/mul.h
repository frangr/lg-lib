#ifndef DEC_H_INCLUDED
#define DEC_H_INCLUDED

#include "../ldrf.h"
#include "ml.h"

class MUL : public ml //multiplexer
{
public:
    MUL(int num_output, int lun_data);

    ~MUL();

    void in_process(ldr::bit vc[]) override;
    void ln_process(ldr::bit vc[]) override;

    ldr::bit m_res(int offst) const override;

private:
    int posi;
};
#endif // DEC_H_INCLUDED
