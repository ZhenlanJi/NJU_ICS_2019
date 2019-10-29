#include "cpu/instr.h"

static void instr_execute_1op()
{
    int writing_size = data_size / 8;
    assert(writing_size == 1 || writing_size == 2 || writing_size == 4);

    OPERAND opr_obj;
    opr_obj.data_size = data_size;
    opr_obj.addr = cpu.esp;
    opr_obj.sreg = SREG_SS;
    opr_obj.type = OPR_MEM;
    operand_read(&opr_obj);

    opr_src.val = opr_obj.val;
    operand_write(&opr_src);
    cpu.esp += writing_size;
}

make_instr_impl_1op(pop, r, v)
make_instr_impl_1op(pop, rm, v)