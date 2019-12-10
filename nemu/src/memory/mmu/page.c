#include "cpu/cpu.h"
#include "memory/memory.h"

// translate from linear address to physical address
paddr_t page_translate(laddr_t laddr)
{
#ifndef TLB_ENABLED
	// printf("\nPlease implement page_translate()\n");
	// assert(0);

	laddrStruct tempLaddr;
	tempLaddr.val = laddr;
	paddr_t table_addr = (cpu.cr3.pdbr << 12) + tempLaddr.dir * sizeof(PDE);

	PDE pde;
	pde.val = paddr_read(table_addr, 4);
	assert(pde.present == 1);

	paddr_t pte_addr=(pde.page_frame<<12)+table_addr
#else
	return tlb_read(laddr) | (laddr & PAGE_MASK);
	;
#endif
}
