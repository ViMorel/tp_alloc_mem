#include <stdlib.h>
#include "alloc_mem.h"
#include "main.h"

void * malloc_3is(size_t size){
    void * addr_break;
    addr_break = sbrk(0);

    header *used = NULL;
    header *free = &free_space_list;

    //parcourt les blocks 
    while(free != NULL){
        if(free->block_size >= size){
            
            used->ptr_next = free->ptr_next;
            used->block_size = size;
            used->magic_number = magic;

            free->ptr_next = used->ptr_next + free->block_size + 1;
            free->block_size = free->block_size - size;
        };
    };
    if(free->ptr_next == NULL){
        
    };

    //Dans le cas ou il n'y a plus de block assez grand
    used->ptr_next = free->ptr_next;
    used->block_size = size;
    used->magic_number = magic;

    addr_break = sbrk(4096);
    free->ptr_next += size + 1;
    free->block_size = free->block_size - size;

    return used->ptr_next;
};

void free_3is(void * ptr){
    //int number_of_used_block = sizeof(used_space_list);

}