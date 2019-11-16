#include "cpu/instr.h"

make_instr_func(call_near)
{
    uint32_t dest_size = data_size / 8;
    assert(dest_size == 1 || dest_size == 2 || dest_size == 4);

    OPERAND rel;
    rel.type = OPR_IMM;
    rel.sreg = SREG_DS;
    rel.data_size = data_size;
    rel.addr = eip + 1;
    operand_read(&rel);
    int offset = sign_ext(rel.val, data_size);

    cpu.esp -= dest_size;

    OPERAND temp_dest;
    temp_dest.addr = cpu.esp;
    temp_dest.sreg = SREG_SS;
    temp_dest.data_size = data_size;
    temp_dest.type = OPR_MEM;
    temp_dest.val = cpu.eip + 1 + dest_size;
    operand_write(&temp_dest);

    cpu.eip += offset;

    return 1 + dest_size;
}

make_instr_func(call_near_indirect)
{
    OPERAND rel;
    rel.sreg = SREG_DS;
    rel.data_size = data_size;
    int tem = modrm_rm(eip + 1, &rel);
    operand_read(&rel);
    
    
}