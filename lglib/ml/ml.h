#ifndef ML_H_INCLUDED
#define ML_H_INCLUDED

#include "../ldrf.h"
#include<math.h>

class ml
{
public:
    ml(int num_input, int lun_input, int, int); //numero input, lunghezza input

    ~ml();

    template<typename... T>
    void set_input(T... ipt); //set input

    template<typename... T>
    void set_output(T... bc); //set lane

    virtual ldr::bit m_res(int offst) const;

protected:
    virtual void in_process(ldr::bit vc[]);
    virtual void ln_process(ldr::bit vc[]);
    int comple, data_l, lane_bit;
    ldr::bit* ip;

    int input_l, output_l;
};

template<typename... T>
void ml::set_input(T... ipt)
{
    ldr::bit vc[input_l] = {std::forward<ldr::bit>(ipt)...};

    in_process(vc);
}

template<typename... T>
void ml::set_output(T... bc)
{
    ldr::bit vc[lane_bit] = {std::forward<ldr::bit>(bc)...}; //lane_bit

    //lane_bit = sizeof...(bc);

    ln_process(vc);
}

#endif // ML_H_INCLUDED
