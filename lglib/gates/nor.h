#ifndef NOR_H_INCLUDED
#define NOR_H_INCLUDED

#include "../ldrf.h"
#include "gate.h"

class NOR : public gate
{
public:
    NOR(int np);

    void process(ldr::bit vc[]) override;
};

#endif // NOR_H_INCLUDED
