#include "cpu/instr.h"

make_instr_func(ret_near)
{
    OPERAND stack_mem;
    stack_mem.data_size=data_size;
    stack_mem.sreg=SREG_SS;
    stack_mem.addr=cpu.esp;
    stack_mem.type=OPR_MEM;

    operand_read(&stack_mem);
    cpu.esp+=data_size/8;
    cpu.eip=stack_mem.val;
}