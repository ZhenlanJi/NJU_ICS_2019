#include "cpu/instr.h"

static void instr_execute_1op()
{
    OPERAND opr_obj;
    opr_obj.addr=cpu.esp;
    opr_obj.sreg=SREG_SS;
    opr_obj.type=OPR_MEM;
    operand_read(&opr_obj);
    opr_src.val=opr_obj.val;
    operand_write(&opr_src);
    cpu.esp+=data_size/8;
}

make_instr_impl_1op(pop, r, v)
make_instr_impl_1op(pop, rm, v)