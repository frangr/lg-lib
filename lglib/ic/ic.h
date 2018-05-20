#ifndef IC_H_INCLUDED
#define IC_H_INCLUDED

#include "../ldrf.h"

class ic
{
public:
    ic(int li); //lunghezza input, numero output(se no=0 allora no=2^li)

    ~ic();

    template<typename... T>
    void setin(T... ipt); //set input

    ldr::bit res(int idx) const;

protected:
    virtual void process(ldr::bit ipt[]);
    int ld, lo;
    ldr::bit* ip;
};

template<typename... T>
void ic::setin(T... ipt)
{
    ldr::bit vc[ld] = {std::forward<ldr::bit>(ipt)...};

    process(vc);
}
#endif // IC_H_INCLUDED
