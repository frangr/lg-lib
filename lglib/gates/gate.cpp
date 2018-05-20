#include "gate.h"

gate::gate(int np):p(np), rs(0){}

ldr::bit gate::res() const {return rs;}

