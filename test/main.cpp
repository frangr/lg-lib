#include "ldr.h"
#include<iostream>

int main()
{
    AND a1(2), a2(2), a3(2), a4(2), a5(4);
    OR o1(2), o2(2), o3(2), o4(2), o5(2), o6(4);

    a1.inpt(1, ldr::NOT(0));
    o1.inpt(1, 0);
    a2.inpt(ldr::NOT(1), 0);
    o2.inpt(ldr::NOT(1), ldr::NOT(0));

    a3.inpt(1, ldr::NOT(0));
    o3.inpt(0, 1);
    a4.inpt(ldr::NOT(1), 1);
    o4.inpt(1, 0);

    a5.inpt(a1.res(), o1.res(), a2.res(), o2.res());
    o6.inpt(a3.res(), o3.res(), a4.res(), o4.res());

    o5.inpt(a5.res(), o6.res());

    std::cout<<o5.res()<<std::endl;
}
