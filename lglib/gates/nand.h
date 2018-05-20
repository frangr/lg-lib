#ifndef NAND_H_INCLUDED
#define NAND_H_INCLUDED

#include "../ldrf.h"
#include "gate.h"

class NAND : public gate
{
public:
    NAND(int np);

    void process(ldr::bit vc[]) override;
};


#endif // NAND_H_INCLUDED
