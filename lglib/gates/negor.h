#ifndef NEGOR_H_INCLUDED
#define NEGOR_H_INCLUDED

#include "../ldrf.h"
#include "gate.h"

class NEGOR : public gate
{
public:
    NEGOR(int np);

    void process(ldr::bit vc[]) override;
};

#endif // NEGOR_H_INCLUDED
