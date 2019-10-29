#include "cpu/instr.h"

make_instr_func(leave)
{
    cpu.esp = cpu.ebp;

    OPERAND opr_obj;
    opr_obj.data_size = data_size;
    opr_obj.addr = cpu.esp;
    opr_obj.sreg = SREG_SS;
    opr_obj.type = OPR_MEM;
    operand_read(&opr_obj);

    cpu.ebp = opr_obj.val;
    cpu.esp += data_size / 8;
    return 1;
}