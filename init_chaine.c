#include "init_chaine.h"
#include <unistd.h>
#include <stdio.h>

#define MAGIC 0x0123456789ABCDEFL
#define INITIAL_HEAP_SIZE 4096   

HEADER* free_list = NULL;  

void init_heap() {
    if (free_list != NULL) return;

    void* start = sbrk(0);
    if (sbrk(INITIAL_HEAP_SIZE) == (void*) -1) {
        perror("sbrk");
        return;
    }

    free_list = (HEADER*) start;
    free_list->ptr_next = NULL;
    free_list->bloc_size = INITIAL_HEAP_SIZE - sizeof(HEADER);
}

void print_free_list() {
    if (free_list == NULL) {
        printf("Free list is empty.\n");
        return;
    }
    printf("Free list:\nAddress: %p, Size: %zu bytes\n", (void*) free_list, free_list->bloc_size);
}
