#ifndef DEK_H_INCLUDED
#define DEK_H_INCLUDED

#include "../ldrf.h"
#include "ic.h"

class DEC : public ic
{
public:
    DEC(int li, int no = 0); //lunghezza input, numero output(se no=0 allora no=2^li)
protected:
    void process(ldr::bit ipt[]) override;
};
#endif // DEK_H_INCLUDED
