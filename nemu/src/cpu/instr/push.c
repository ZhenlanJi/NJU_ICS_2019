#include "cpu/instr.h"

static void instr_execute_1op()
{
    uint32_t dest_size = data_size / 8;
    assert(dest_size == 1 || dest_size == 2 || dest_size == 4);
    cpu.esp -= dest_size;

    operand_read(&opr_src);

    OPERAND temp_dest;
    temp_dest.addr = cpu.esp;
    temp_dest.sreg = SREG_SS;
    temp_dest.data_size = data_size;
    temp_dest.type = OPR_MEM;
    temp_dest.val = sign_ext(opr_src.val, data_size);
    operand_write(&temp_dest);
}

make_instr_impl_1op(push, r, v)
make_instr_impl_1op(push, rm, v)
make_instr_impl_1op(push, i, b)
make_instr_impl_1op(push, i, v)

make_instr_func(pusha)
{
    OPERAND rel;
    rel.data_size = data_size;
    rel.type = OPR_MEM;
    rel.sreg = SREG_SS;

    uint32_t offset = data_size / 8;
    //in order eax,ecx,edx.....
    for (int i = 0; i < 8; i++)
    {
        cpu.esp -= offset;
        
    }
}