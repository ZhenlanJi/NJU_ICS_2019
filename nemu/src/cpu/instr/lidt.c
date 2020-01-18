#include "cpu/instr.h"

make_instr_func(lidt)
{
    int len = 1;
    OPERAND limit, base;

    limit.type = OPR_IMM;
    limit.data_size = 16;
    limit.addr = eip + 1;
    len += modrm_rm(eip + 1, &limit);
    operand_read(&limit);
    cpu.idtr.limit = limit.val;

    base.type = OPR_IMM;
    base.data_size = 32;
    base.addr = limit.addr + 2;
    operand_read(&base);
    cpu.idtr.base = base.val;

    return 6;

    // int len = 1;
    // OPERAND rel;
    // len += modrm_rm(eip + 1, &rel);

    // rel.data_size = 16;
    // operand_read(&rel);
    // cpu.idtr.limit = rel.val;

    // rel.data_size = 32;
    // rel.addr += 2;
    // operand_read(&rel);
    // cpu.idtr.base = rel.val;

    // return len;
}
