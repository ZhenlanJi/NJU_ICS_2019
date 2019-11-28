#include "memory/memory.h"
#include "memory/cache.h"

CacheLine CACHE[CACHE_LINE_NUM]; //1024

void init_cache()
{
    memset(CACHE, 0, 1024 * sizeof(CacheLine));
}

uint32_t cache_read(paddr_t paddr, size_t len, CacheLine *cache)
{
    uint32_t ret = 0;

    paddr2Cache pRead;
    pRead.val = paddr;

    int cache_row = CACHE_SET_ASSOCIATE * pRead.grpNo;
    for (int i = 0; i < CACHE_SET_ASSOCIATE; i++)
    {
        if (cache[cache_row + i].mark == pRead.mark)
        {
            cache_row += i;
            if (cache[cache_row].valid_bit)
            {
                if (pRead.blockAddr + 8 * len < 512)
                {
                    memcpy(&ret, cache[cache_row].data[pRead.blockAddr], len);
                }
                else
                {
                    uint32_t head, tail;
                    memcpy(&tail, cache[cache_row].data[pRead.blockAddr], len);
                    head = cache_read(paddr + 64 - pRead.blockAddr, len + 64 - pRead.blockAddr, cache) << (8 * (64 - pRead.blockAddr));
                    ret = head | tail;
                }
                return ret;
            }
        }
    }
    //fail need to write
    cache_row += rand() % 8;
    cache[cache_row].valid_bit = true;
    cache[cache_row].mark = pRead.mark;
    memcpy(cache[cache_row].data, hw_mem + paddr - pRead.blockAddr, CACHE_BLOCK_SIZE);
    memcpy(&ret, hw_mem + paddr, len);
    return ret;
}