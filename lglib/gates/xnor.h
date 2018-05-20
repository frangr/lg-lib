#ifndef XNOR_H_INCLUDED
#define XNOR_H_INCLUDED

#include "../ldrf.h"
#include "gate.h"

class XNOR : public gate
{
public:
    XNOR(int np);

    void process(ldr::bit vc[]) override;
};

#endif // XNOR_H_INCLUDED
