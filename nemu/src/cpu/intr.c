#include "cpu/intr.h"
#include "cpu/instr.h"
#include "memory/memory.h"

void raise_intr(uint8_t intr_no)
{
#ifdef IA32_INTR
	// printf("Please implement raise_intr()");
	// assert(0);
	//printf("intr_no: %x\n", intr_no);
	cpu.esp -= 4;
	vaddr_write(cpu.esp, SREG_SS, 4, cpu.eflags.val);
	cpu.esp -= 4;
	vaddr_write(cpu.esp, SREG_SS, 4, cpu.cs.val);
	cpu.esp -= 4;
	vaddr_write(cpu.esp, SREG_SS, 4, cpu.eip);

	laddr_t l_addr = cpu.idtr.base + sizeof(GateDesc) * intr_no;
	GateDesc gatedesc;
	gatedesc.val[0] = laddr_read(l_addr, 4);
	gatedesc.val[1] = laddr_read(l_addr + 4, 4);

	assert(gatedesc.present == 1 && gatedesc.system == 0 && gatedesc.pad0 == 0);

	if (gatedesc.type == 0xe)
		cpu.eflags.IF = 0;

	//cpu.cs.val = gatedesc.selector;
	cpu.eip = ((gatedesc.offset_31_16 << 16) + gatedesc.offset_15_0);
	//printf("eip: %x\n", cpu.eip);
#endif
}

void raise_sw_intr(uint8_t intr_no)
{
	// return address is the next instruction
	cpu.eip += 2;
	raise_intr(intr_no);
}
