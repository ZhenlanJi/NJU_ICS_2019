#include "cpu/instr.h"

static void instr_execute_2op()
{
    operand_read(&opr_src);
    operand_read(&opr_dest);
    alu_and(opr_src.val, opr_dest.val, data_size);
}
