#include "cpu/intr.h"
#include "cpu/instr.h"
#include "memory/memory.h"

void raise_intr(uint8_t intr_no)
{
#ifdef IA32_INTR
	// printf("Please implement raise_intr()");
	// assert(0);
	cpu.esp -= 4;
	vaddr_write(cpu.esp, SREG_SS, 4, cpu.eflags.val);
	cpu.esp -= 2;
	vaddr_write(cpu.esp, SREG_SS, 2, cpu.cs.val);
	cpu.esp -= 4;
	vaddr_write(cpu.esp, SREG_SS, 4, cpu.eip);

	GateDesc gatedesc;
	gatedesc = (uint32_t)hw_mem + page_translate(segment_translate(cpu.idtr.base + 8 * intr_no, SREG_DS));
	assert(gatedesc.present == 1 && gatedesc.system == 0 && gatedesc.pad0 == 0);

	if(gatedesc.type == 0xe)
		cpu.eflags.IF = 0;

	cpu.eip = (gatedesc.offset_31_16<<16)+ gatedesc.offset_15_0;
#endif
}

void raise_sw_intr(uint8_t intr_no)
{
	// return address is the next instruction
	cpu.eip += 2;
	raise_intr(intr_no);
}
