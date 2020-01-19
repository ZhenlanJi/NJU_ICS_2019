#include "cpu/instr.h"
#include "device/port_io.h"

make_instr_func(in_b)
{
    cpu.eax = pio_read((uint16_t)cpu.edx, 1);
    return 1;
}

make_instr_func(in_v)
{
    cpu.eax = pio_read((uint16_t)cpu.edx, data_size / 8);
    return 1;
}

make_instr_func(out_b)
{
    pio_write((uint16_t)cpu.edx, 1, cpu.eax);
    return 1;
}