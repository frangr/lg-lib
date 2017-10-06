#include "lglib/ldr.h"
#include<iostream>

int main()
{
    AND And(2);
    NAND Nand(2);
    OR Or(2);
    NOR Nor(2);
    NEGAND Negand(2);
    NEGOR Negor(2);
    XOR Xor(2);
    XNOR Xnor(2);

    //truth tables
    std::cout<<"AND TABLE:"<<std::endl;
    And.inpt(0, 0);
    std::cout<<And.res()<<std::endl;
    And.inpt(0, 1);
    std::cout<<And.res()<<std::endl;
    And.inpt(1, 0);
    std::cout<<And.res()<<std::endl;
    And.inpt(1, 1);
    std::cout<<And.res()<<std::endl;
    std::cout<<std::endl;

    std::cout<<"NAND TABLE:"<<std::endl;
    Nand.inpt(0, 0);
    std::cout<<Nand.res()<<std::endl;
    Nand.inpt(0, 1);
    std::cout<<Nand.res()<<std::endl;
    Nand.inpt(1, 0);
    std::cout<<Nand.res()<<std::endl;
    Nand.inpt(1, 1);
    std::cout<<Nand.res()<<std::endl;
    std::cout<<std::endl;

    std::cout<<"OR TABLE:"<<std::endl;
    Or.inpt(0, 0);
    std::cout<<Or.res()<<std::endl;
    Or.inpt(0, 1);
    std::cout<<Or.res()<<std::endl;
    Or.inpt(1, 0);
    std::cout<<Or.res()<<std::endl;
    Or.inpt(1, 1);
    std::cout<<Or.res()<<std::endl;
    std::cout<<std::endl;

    std::cout<<"NOR TABLE:"<<std::endl;
    Nor.inpt(0, 0);
    std::cout<<Nor.res()<<std::endl;
    Nor.inpt(0, 1);
    std::cout<<Nor.res()<<std::endl;
    Nor.inpt(1, 0);
    std::cout<<Nor.res()<<std::endl;
    Nor.inpt(1, 1);
    std::cout<<Nor.res()<<std::endl;
    std::cout<<std::endl;

    std::cout<<"XOR TABLE:"<<std::endl;
    Xor.inpt(0, 0);
    std::cout<<Xor.res()<<std::endl;
    Xor.inpt(0, 1);
    std::cout<<Xor.res()<<std::endl;
    Xor.inpt(1, 0);
    std::cout<<Xor.res()<<std::endl;
    Xor.inpt(1, 1);
    std::cout<<Xor.res()<<std::endl;
    std::cout<<std::endl;

    std::cout<<"XNOR TABLE:"<<std::endl;
    Xnor.inpt(0, 0);
    std::cout<<Xnor.res()<<std::endl;
    Xnor.inpt(0, 1);
    std::cout<<Xnor.res()<<std::endl;
    Xnor.inpt(1, 0);
    std::cout<<Xnor.res()<<std::endl;
    Xnor.inpt(1, 1);
    std::cout<<Xnor.res()<<std::endl;
    std::cout<<std::endl;

    std::cout<<"NEGAND TABLE:"<<std::endl;
    Negand.inpt(0, 0);
    std::cout<<Negand.res()<<std::endl;
    Negand.inpt(0, 1);
    std::cout<<Negand.res()<<std::endl;
    Negand.inpt(1, 0);
    std::cout<<Negand.res()<<std::endl;
    Negand.inpt(1, 1);
    std::cout<<Negand.res()<<std::endl;
    std::cout<<std::endl;

    std::cout<<"NEGOR TABLE:"<<std::endl;
    Negor.inpt(0, 0);
    std::cout<<Negor.res()<<std::endl;
    Negor.inpt(0, 1);
    std::cout<<Negor.res()<<std::endl;
    Negor.inpt(1, 0);
    std::cout<<Negor.res()<<std::endl;
    Negor.inpt(1, 1);
    std::cout<<Negor.res()<<std::endl;
    std::cout<<std::endl;

    //circuit example
    XOR xr(2);
    AND ad(2);
    NAND nad(2);
    NOR nor(2);
    NEGAND ngad(2);
    XNOR xnr(3);
    NEGOR ngr(3);
    OR r(2);
    MEM mm(2, 4);

    xr.inpt(1, 0);
    ad.inpt(1, 1);
    nad.inpt(ldr::NOT(1), ldr::NOT(1));
    nor.inpt(ldr::NOT(0), 0);
    ngad.inpt(0, 1);

    xnr.inpt(ldr::NOT(xr.res()), ad.res(), nad.res());
    ngr.inpt(nor.res(), ldr::NOT(ngad.res()), ngad.res());

    r.inpt(xnr.res(), ngr.res());
    std::cout<<"circ result: "<<r.res()<<std::endl;
    std::cout<<"binary to decimal test: "<<ldr::btn(0, 0, 1, 1, 0, 1, 1, 0)<<std::endl;

    mm.setwd(0, 0, 0, 1);//write data = 0001
    mm.memf(1, 0, 0);//write 0001 at 00

    mm.setwd(0, 0, 1, 0);//write data = 0010
    mm.memf(1, 0, 1);//write 0010 at 01

    mm.setwd(0, 1, 0, 0);//write data = 0100
    mm.memf(1, 1, 0);//write 0001 at 10

    mm.setwd(1, 0, 0, 0);//write data = 1000
    mm.memf(1, 1, 1);//write 0001 at 11

    mm.memf(0, 0, 1); //read at 01 address

    std::cout<<"read at 01: "<<mm.res(0)<<mm.res(1)<<mm.res(2)<<mm.res(3)<<std::endl;

    ALU al(2, 4); //ALU with two 4-bit-operand
    al.aluf(0, 0, //00=add, 01=subtract, 10=multiplication, 11=division
            0, 0, 1, 1,
            0, 1, 0, 1
            );
    std::cout<<"ALU result: "<<al.r_res(0)<<al.r_res(1)<<al.r_res(2)<<al.r_res(3)<<std::endl; //ALU result
    std::cout<<"zero flag: "<<al.getflag(0)<<std::endl //ALU flags
             <<"negative flag: "<<al.getflag(1)<<std::endl
             <<"overflow flag: "<<al.getflag(2);
}
