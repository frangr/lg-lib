#include "alu.h"

ALU::ALU(int li):l(li), rs(new bit[l]) //li = lunghezza input
{
    //for(int i = 0; i<li; i++)
        //rs[i] = 0;
}

ALU::~ALU()
{
    delete [] rs;
}

void ALU::set_op(bit ope1, bit ope2)
{
    op1 = ope1;
    op2 = ope2;
}

bit ALU::r_res(int idx)
{
    //return rs[(rs.size() - idx) - 1];
    return rs[idx];
}

bit ALU::getflag(int idx)
{
    return flag[idx];
}

void ALU::add(bit bf[]) //nci = numero cicli
{
    /*
    se A=1, B=1, carry = 0, allora rs = 0, carry = 1
    se A != B, carry = 1, allora rs = 0, carry = 1
    se A=1, B=1, carry = 1, allora rs = 1, carry = 1
    */

    bit carry = 0;

    flag[0] = 1;

    for(int cou = l-1; cou>=0; cou--) //calcola ogni bit di ogni operando
    {
        if(bf[cou] == 1 && bf[l+cou] == 1) // se A = 1 e B = 1
        {
            rs[cou] = carry; //prende il valore di carry prima che venga ri-settato, perchè se A=1, B=1, carry = 1, allora rs = 1, carry = 1 e se A=1, B=1, carry = 0, allora rs = 0, carry = 1
            carry = 1; //carry è 1 se A=1 e B=1
        }
        else if(bf[cou] != bf[l+cou])//se A o B sono = 1
        {
            if(carry == 1) //Se carry = 1
            {
                carry = 1;
                rs[cou] = 0; //carry sarà 1 e rs 0 perchè se A != B, carry = 1, allora rs = 0, carry = 1
            }
            else
            {
                rs[cou] = 1; //se carry = 0, si fa semplicemente 1+0 oppure 0+1 (rs. 1)
            }
        }
        else if(bf[cou] == 0 && bf[l+cou] == 0)
        {
            rs[cou] = carry; //Se A e B sono 0, somma carry a rs
            carry = 0;
        }

        if(cou == 0 && carry == 1) //OVERFLOW FLAG i == l && carry == 1 i == l-1 && i = l-1 && rs[i] == 1 && bf[spos] == 1
        {
            flag[2] = 1; //setta overflow flag a 1
        }
    }

    if(!flag[2])
    {
        for(int i = 0; i<l; i++)
        {
            if(rs[i]) //ZERO FLAG
                flag[0] = 0;
        }
    }
    else
        flag[0] = 0;
}

void ALU::uadd(bit bf[]) //nci = numero cicli
{
    /*
    se A=1, B=1, carry = 0, allora rs = 0, carry = 1
    se A != B, carry = 1, allora rs = 0, carry = 1
    se A=1, B=1, carry = 1, allora rs = 1, carry = 1
    */

    bit carry = 0;

    flag[0] = 1;

    for(int cou = l-1; cou>=0; cou--) //calcola ogni bit di ogni operando
    {
        if(bf[cou] == 1 && rs[cou] == 1) // se A = 1 e B = 1
        {
            rs[cou] = carry; //prende il valore di carry prima che venga ri-settato, perchè se A=1, B=1, carry = 1, allora rs = 1, carry = 1 e se A=1, B=1, carry = 0, allora rs = 0, carry = 1
            carry = 1; //carry è 1 se A=1 e B=1
        }
        else if(bf[cou] != rs[cou])//se A o B sono = 1
        {
            if(carry == 1) //Se carry = 1
            {
                    carry = 1;
                    rs[cou] = 0; //carry sarà 1 e rs 0 perchè se A != B, carry = 1, allora rs = 0, carry = 1
            }
            else
            {
                    rs[cou] = 1; //se carry = 0, si fa semplicemente 1+0 oppure 0+1 (rs. 1)
            }
        }
        else if(bf[cou] == 0 && rs[cou] == 0)
        {
                rs[cou] = carry; //Se A e B sono 0, somma carry a rs
                carry = 0;
        }

        if(cou == 0 && carry == 1) //OVERFLOW FLAG i == l && carry == 1 i == l-1 && i = l-1 && rs[i] == 1 && bf[spos] == 1
        {
            flag[2] = 1; //setta overflow flag a 1
        }
    }

    if(!flag[2])
    {
        for(int i = 0; i<l; i++)
        {
            if(rs[i]) //ZERO FLAG
                flag[0] = 0;
        }
    }
    else
        flag[0] = 0;
}

void ALU::sub(bit bf[])
{
    flag[0] = 1;

    bool cp = false;

    for(int i = l-1; i>=0 && !cp; i--) //calcola ogni bit di ogni operando
    {
        if(bf[i] == 0 && bf[l+i] == 1) //sottrazione con riporto da sinistra
        {
            bool cb = false;
            int ps = i-1;

            rs[i] = 1;

            while(!cb)
            {
                if(!bf[ps])
                {
                    bf[ps] = 1;
                    ps--;
                }
                else
                {
                    bf[ps] = 0;
                    cb = true;
                }

                if(ps < 0) //NEGATIVE FLAG
                {
                    flag[1] = 1; //negative flag = 1
                    cp = true; //ferma ciclo
                    cb = true;
                }
            }
        }
        else
        {
            rs[i] = bf[i] - bf[l+i]; //sottrazione normale se A e B sono 0, 0 oppure 1, 0 oppure 1, 1
        }
    }

    if(!flag[1])
    {
        for(int i = 0; i<l; i++)
        {
            if(rs[i]) //ZERO FLAG
                flag[0] = 0;
        }
    }
    else
        flag[0] = 0;
}

void ALU::usub(bit bf[])
{
    flag[0] = 1;

    bool cp = false;

    for(int i = l-1; i>=0 && !cp; i--) //calcola ogni bit di ogni operando
    {
        if(rs[i] == 0 && bf[i] == 1) //sottrazione con riporto da sinistra
        {
            bool cb = false;
            int ps = i-1;

            rs[i] = 1;

            while(!cb)
            {

                if(!rs[ps])
                {
                    rs[ps] = 1;
                    ps--;
                }
                else
                {
                    rs[ps] = 0;
                    cb = true;
                }

                if(ps < 0) //NEGATIVE FLAG
                {
                    flag[1] = 1; //negative flag = 1
                    cp = true; //ferma ciclo
                    cb = true;
                }
            }
        }
        else
        {
            rs[i] = bf[i] - rs[i]; //sottrazione normale se A e B sono 0, 0 oppure 1, 0 oppure 1, 1
        }
    }


    if(!flag[1])
    {
        for(int i = 0; i<l; i++)
        {
            if(rs[i]) //ZERO FLAG
                flag[0] = 0;
        }
    }
    else
        flag[0] = 0;
}
