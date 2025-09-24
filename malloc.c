#include "malloc.h"
#include "init_chaine.h"
#include "init_chaine.c"

#define BLOCK_SIZE 4096
#define NB_BLOCKS 3
#define MAGIC 0x0123456789ABCDEFL

void init_heap_multiple() {
    for (int i = 0; i < NB_BLOCKS; i++) {
        void* start = sbrk(BLOCK_SIZE);

        if (start == (void*) -1) {
            perror("sbrk failed");
            return;
        }


        HEADER* block = (HEADER*) start;
        block->ptr_next = free_list;
        block->bloc_size = BLOCK_SIZE - sizeof(HEADER);
        block->magic_number = MAGIC;

        free_list = block;
    }
}

