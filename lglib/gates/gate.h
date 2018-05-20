#ifndef GATE_H_INCLUDED
#define GATE_H_INCLUDED

#include "../ldrf.h"

class gate
{
public:
    gate(int np);

    template<typename... T>
    void inpt(T... b);
    ldr::bit res() const;

protected:
    virtual void process(ldr::bit vc[]) = 0;
    int p;
    ldr::bit rs;
};

template<typename... T>
void gate::inpt(T... b)
{
    ldr::bit vc[p] = {std::forward<ldr::bit>(b)...};

    process(vc);
}
#endif // GATE_H_INCLUDED
