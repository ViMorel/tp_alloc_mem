#include <stdlib.h>
#include "alloc_mem.h"
#include "main.h"

void * malloc_3is(size){
    void * addr_break;
    addr_break = sbrk(0);

    if(free_space_list.block_size>=size){

        used_space_list.ptr_next = free_space_list.ptr_next;
        used_space_list.block_size = size;
        used_space_list.magic_number = magic;

        free_space_list.ptr_next += size + 1;
        free_space_list.block_size = free_space_list.block_size - size;
        
    };
    if(free_space_list.block_size < size){

        used_space_list.ptr_next = free_space_list.ptr_next;
        used_space_list.block_size = size;
        used_space_list.magic_number = magic;

        addr_break = sbrk(4096);
        free_space_list.ptr_next += size + 1;
        free_space_list.block_size = free_space_list.block_size - size;
    };
};

void free_3is(ptr){
    int number_of_used_block = sizeof(used_space_list);

}