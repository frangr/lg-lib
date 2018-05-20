#ifndef OR_H_INCLUDED
#define OR_H_INCLUDED

#include "../ldrf.h"
#include "gate.h"

class OR : public gate
{
public:
    OR(int np);

    void process(ldr::bit vc[]) override;
};

#endif // OR_H_INCLUDED
