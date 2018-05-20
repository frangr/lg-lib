#ifndef XOR_H_INCLUDED
#define XOR_H_INCLUDED

#include "../ldrf.h"
#include "gate.h"

class XOR : public gate
{
public:
    XOR(int np);

    void process(ldr::bit vc[]) override;
};

#endif // XOR_H_INCLUDED
