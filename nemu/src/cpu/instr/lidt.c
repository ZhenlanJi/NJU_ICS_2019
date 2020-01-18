#include "cpu/instr.h"

make_instr_func(lidt)
{
    int len = 1;
    OPERAND limit, base;

    base.type = OPR_IMM;
    base.data_size = 32;
    limit.type = OPR_IMM;
    limit.data_size = 16;
    limit.addr

}
