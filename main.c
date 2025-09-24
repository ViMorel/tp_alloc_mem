#include "main.h"
#include "alloc_mem.h"

int main(){
    
    void * addr_breack = sbrk(0);
    free_space_list.ptr_next = addr_breack;
}