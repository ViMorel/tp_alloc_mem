#include "malloc.h"

#define BLOCK_SIZE 4096



void* start = sbrk(BLOCK_SIZE);

if (start == (void*) -1) {
    perror("sbrk failed");
    return;
    
}

HEADER* new_block = (HEADER*) start;
new_block->ptr_next = NULL;
new_block->bloc_size = BLOCK_SIZE - sizeof(HEADER);
new_block->magic_number = MAGIC;
