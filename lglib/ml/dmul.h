#ifndef DMUL_H_INCLUDED
#define DMUL_H_INCLUDED

#include "../ldrf.h"
#include "ml.h"

class DMUL : public ml
{
public:
    DMUL(int num_output, int lun_data); //lunghezza data, numero linee (output)

    ~DMUL();

    void in_process(ldr::bit vc[]) override;
    void ln_process(ldr::bit vc[]) override;

    ldr::bit m_res(int offst) const override;

private:
    ldr::bit* dt;
};
#endif // DMUL_H_INCLUDED
