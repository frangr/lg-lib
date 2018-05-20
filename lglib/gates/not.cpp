#include "not.h"

void NOT::not_input(ldr::bit inpt){state = inpt-1;}

ldr::bit NOT::not_res() const {return state;}
