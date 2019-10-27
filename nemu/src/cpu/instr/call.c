#include "cpu/instr.h"

make_instr_func(call_near)
{
        uint32_t dest_size = data_size / 8;
    assert(dest_size == 1 || dest_size == 2 || dest_size == 4);
        
        OPERAND rel;
        rel.type = OPR_IMM;
        rel.sreg = SREG_CS;
        rel.data_size = data_size;
        rel.addr = eip + 1;

        operand_read(&rel);

        int offset = sign_ext(rel.val, data_size);
        // thank Ting Xu from CS'17 for finding this bug
        print_asm_1("jmp", "", 1 + data_size / 8, &rel);

        cpu.eip += offset;

        return 1 + data_size / 8;
}