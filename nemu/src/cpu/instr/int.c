#include "cpu/instr.h"
#include "cpu/intr.h"

make_instr_func(int_)
{
    OPERAND rel;
    rel.data_size = 8;
    rel.type = OPR_IMM;
    rel.sreg = SREG_CS;
    rel.addr = eip + 1;
    operand_read(&rel);
    raise_sw_intr(rel.val);
    return 0;
}