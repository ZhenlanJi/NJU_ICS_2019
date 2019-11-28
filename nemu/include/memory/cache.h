#include "nemu.h"

#define CACHE_LINE_NUM 1024
#define CACHE_BLOCK_SIZE 64


typedef struct cacheLineStru
{
    bool valid_bit; //1
    uint32_t mark;  //19
    uint8_t data[CACHE_BLOCK_SIZE];
}CacheLine;

// 64=2^b b=6  blockAddr
// 2^10/2^3=2^q q=7 grp_no
// 32-6-7=19 t=19  mark
typedef struct paddr2CacheStru
{
    struct 
    {
        uint32_t mark:19;
        uint32_t grpNo: 7;
        uint32_t blockAddr:6;
    };
    uint32_t val;
}paddr2Cache;

extern CacheLine CACHE[];

void init_cache();

uint32_t cache_read(paddr_t paddr, size_t len, CacheLine *cache);

void cache_write(paddr_t paddr, size_t len, uint32_t data, CacheLine *cache);