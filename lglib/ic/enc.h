#ifndef ENC_H_INCLUDED
#define ENC_H_INCLUDED

#include "../ldrf.h"
#include "ic.h"

class ENC : public ic
{
public:
    ENC(int li, int no = 0);
protected:
    void process(ldr::bit ipt[]) override;
};
#endif // ENC_H_INCLUDED
