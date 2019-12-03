#include "cpu/cpu.h"
#include "memory/memory.h"

// return the linear address from the virtual address and segment selector
uint32_t segment_translate(uint32_t offset, uint8_t sreg)
{
	/* TODO: perform segment translation from virtual address to linear address
	 * by reading the invisible part of the segment register 'sreg'
	 */
	assert(sreg >= 0 && sreg <= 5);
	return cpu.segReg[sreg].base + offset;
}

// load the invisible part of a segment register
void load_sreg(uint8_t sreg)
{
	/* TODO: load the invisibile part of the segment register 'sreg' by reading the GDT.
	 * The visible part of 'sreg' should be assigned by mov or ljmp already.
	 */
	assert(sreg >= 0 && sreg <= 5);
	assert(cpu.segReg[sreg].base == 0 && cpu.segReg[sreg].limit == 0);
	SegDesc *base_GDT = (SegDesc *)cpu.gdtr.base;
	SegDesc *obj_GDT = (SegDesc *)(base_GDT + cpu.segReg[sreg].index * sizeof(SegDesc));
	assert(obj_GDT->granularity == 0 && obj_GDT->present == 1);

	cpu.segReg[sreg].base = obj_GDT->base_15_0 + (obj_GDT->base_23_16 << 16) + (obj_GDT->base_32_24 << 24);
	cpu.segReg[sreg].limit = obj_GDT->limit_15_0 + (obj_GDT->limit_19_16 << 16);
}
