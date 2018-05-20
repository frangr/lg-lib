#ifndef NEGAND_H_INCLUDED
#define NEGAND_H_INCLUDED

#include "../ldrf.h"
#include "gate.h"

class NEGAND : public gate
{
public:
    NEGAND(int np);

    void process(ldr::bit vc[]) override;
};

#endif // NEGAND_H_INCLUDED
