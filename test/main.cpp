#include "../lglib/ldr.h"
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

    //circuit example, circuit located at test/crc.png
    XOR xr(2);
    AND ad(2);
    NAND nad(2);
    NOR nor(2);
    NEGAND ngad(2);
    XNOR xnr(3);
    NEGOR ngr(3);
    OR r(2);
    MEM mm(2, 4);
    NOT n1, n2, n3, n4, n5;



    xr.inpt(1, 0);
    ad.inpt(1, 1);
    n1.not_input(1);
    n2.not_input(1);
    n3.not_input(0);
    nad.inpt(n1.not_res(), n2.not_res());
    nor.inpt(n3.not_res(), 0);
    ngad.inpt(0, 1);

    n4.not_input(xr.res());
    n5.not_input(ngad.res());
    xnr.inpt(n4.not_res(), ad.res(), nad.res());
    ngr.inpt(nor.res(), n5.not_res(), ngad.res());

    r.inpt(xnr.res(), ngr.res());
    std::cout<<"circ result: "<<r.res()<<std::endl;
    std::cout<<"binary to decimal test: "<<ldr::btn(0, 0, 1, 1, 0, 1, 1, 0)<<std::endl;

    mm.set_rw(1); //set read/write control bit with 1 (write)

    mm.setwd(0, 0, 0, 1);//write data = 0001
    mm.memf(0, 0);//write 0001 at 00

    mm.setwd(0, 0, 1, 0);//write data = 0010
    mm.memf(0, 1);//write 0010 at 01

    mm.setwd(0, 1, 0, 0);//write data = 0100
    mm.memf(1, 0);//write 0100 at 10

    mm.setwd(1, 0, 0, 0);//write data = 1000
    mm.memf(1, 1);//write 1000 at 11

    mm.set_rw(0); //set read/write control bit with 0 (read)

    mm.memf(0, 1); //read at 01 address

    std::cout<<"read at 01: "<<mm.res(0)<<mm.res(1)<<mm.res(2)<<mm.res(3)<<std::endl;

    ALU al(4); //ALU with two 4-bit-operand

    al.set_op(0, 0); //00=add, 01=subtract, 10=multiplication, 11=division

    al.aluf(//ALU operands
            0, 1, 1, 1,
            0, 0, 1, 0
            );
    std::cout<<"ALU result: "<<al.r_res(0)<<al.r_res(1)<<al.r_res(2)<<al.r_res(3)<<std::endl; //ALU result
    std::cout<<"zero flag: "<<al.getflag(0)<<std::endl //ALU flags
             <<"negative flag: "<<al.getflag(1)<<std::endl
             <<"overflow flag: "<<al.getflag(2)<<std::endl
             <<"division by zero flag: "<<al.getflag(3)<<std::endl;

    MUL mll(2, 2); //multiplexer with two 2-bit inputs

    mll.set_input(0, 0, //input data
                 1, 1);

    mll.set_output(0); //00
    std::cout<<"multiplexer 0: "<<mll.m_res(0)<<mll.m_res(1)<<std::endl;
    mll.set_output(1); //11
    std::cout<<"multiplexer 1: "<<mll.m_res(0)<<mll.m_res(1)<<std::endl;

    DMUL dm(4, 2);
    DEC  dc(2, 4);
    ENC  ec(4, 2);

    dm.set_input(1, 1);
    dm.set_output(1, 0);

    std::cout<<"Demultiplexer output: "
             <<dm.m_res(0)
             <<dm.m_res(1)
             <<"-"
             <<dm.m_res(2)
             <<dm.m_res(3)
             <<"-"
             <<dm.m_res(4)
             <<dm.m_res(5)
             <<"-"
             <<dm.m_res(6)
             <<dm.m_res(7)<<std::endl;

    dc.setin(1, 1);

    std::cout<<"Decoder output: "<<dc.res(0)<<"-"<<dc.res(1)<<"-"<<dc.res(2)<<"-"<<dc.res(3)<<std::endl;

    ec.setin(0, 1, 0, 0);
    std::cout<<"Encoder output: "<<ec.res(0)<<ec.res(1)<<std::endl;

    ic* ict = new DEC(2, 4);
    ml* test = new MUL(2, 2);
    gate* gtt = new AND(2);


    gtt->inpt(1, 0);
    std::cout<<"gtt AND: "<<gtt->res()<<std::endl;
    delete gtt;

    gtt = new OR(3);
    gtt->inpt(1, 1, 1);
    std::cout<<"gtt OR: "<<gtt->res()<<std::endl;

    ict->setin(1, 1);
    std::cout<<"ict Decoder output: "<<ict->res(0)<<"-"<<ict->res(1)<<"-"<<ict->res(2)<<"-"<<ict->res(3)<<std::endl;

    test->set_input(0, 0, //input data
                 1, 1);
    test->set_output(0); //00
    std::cout<<"test multiplexer 0: "<<test->m_res(0)<<test->m_res(1)<<std::endl;
    test->set_output(1); //11
    std::cout<<"test multiplexer 1: "<<test->m_res(0)<<test->m_res(1)<<std::endl;
}
