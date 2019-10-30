#include "cpu/instr.h"

make_instr_func(ret_near)
{
    OPERAND stack_mem;
    stack_mem.data_size = data_size;
    stack_mem.sreg = SREG_SS;
    stack_mem.addr = cpu.esp;
    stack_mem.type = OPR_MEM;

    operand_read(&stack_mem);
    cpu.esp += data_size / 8;
    cpu.eip = stack_mem.val;

    return 0;
}

make_instr_func(ret_near_imm16)
{
    OPERAND stack_mem;
    stack_mem.data_size = data_size;
    stack_mem.sreg = SREG_SS;
    stack_mem.addr = cpu.esp;
    stack_mem.type = OPR_MEM;

    operand_read(&stack_mem);
    operand_read(&opr_src);
    cpu.eip = stack_mem.val;
    int offset = sign_ext(instr_fetch(cpu.eip + 1, 2), 16);
    cpu.esp += data_size / 8 + offset;

    return 0;
}