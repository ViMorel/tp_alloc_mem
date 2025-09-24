#include "malloc.h"
#include <stdio.h>
#include <unistd.h>

#define BLOCK_SIZE 4096
#define MAGIC 0x0123456789ABCDEFL

void init_heap_multiple(int nb_blocks) {
    for (int i = 0; i < nb_blocks; i++) {
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

void* malloc_3is(size_t size) {
    if (size == 0) return NULL;

    HEADER* prev = NULL;
    HEADER* current = free_list;

    // Chercher un bloc libre suffisant
    while (current != NULL) {
        if (current->bloc_size >= size) {
            
            if (prev)
                prev->ptr_next = current->ptr_next;
            else
                free_list = current->ptr_next;

            current->ptr_next = NULL;
            return (void*)((char*)current + sizeof(HEADER));
        }

        prev = current;
        current = current->ptr_next;
    }

    // pas de block libre suffisant, demander plus de mémoire
    size_t total_size = size + sizeof(HEADER);
    void* start = sbrk(total_size);
    if (start == (void*) -1) {
        perror("sbrk failed");
        return NULL;
    }

    HEADER* new_block = (HEADER*) start;
    new_block->bloc_size = size;
    new_block->ptr_next = NULL;
    new_block->magic_number = MAGIC;

    return (void*)((char*)new_block + sizeof(HEADER));
}
