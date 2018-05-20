#ifndef AND_H_INCLUDED
#define AND_H_INCLUDED

#include "../ldrf.h"
#include "gate.h"

class AND : public gate
{
public:
    AND(int np);
    void process(ldr::bit vc[]) override;
};
#endif // AND_H_INCLUDED
