#include "memory/memory.h"
#include "memory/cache.h"

CacheLine CACHE[CACHE_LINE_NUM]; //1024

void init_cache()
{
    memset(CACHE, 0, 1024 * sizeof(CacheLine));
}

uint32_t cache_read(paddr_t paddr, size_t len, CacheLine *cache)
{
    
}