#ifndef NOT_H_INCLUDED
#define NOT_H_INCLUDED

#include "../ldrf.h"

class NOT
{
public:
    void not_input(ldr::bit);
    ldr::bit not_res() const;
private:
    ldr::bit state;
};

#endif // NOT_H_INCLUDED
