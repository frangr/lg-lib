#include<iostream>
#include "ldr.h"

int main()
{
    AND a1, a2, a3, a4;
    OR o1, o2;

    a1.inpt(1, 1);
    a2.inpt(1, 0);
    o1.inpt(a2.res(), 1);
    o2.inpt(ldr::NOT(a1.res()), o2.res());
    a3.inpt(a1.res(), o1.res());
    a4.inpt(o2.res(), a3.res());

    std::cout<<"res: "<<a4.res()<<std::endl;
}
