#include "init_chaine.h"


#define MAGIC 0x0123456789ABCDEFL
#define INITIAL_HEAP_SIZE 4096   

typedef struct HEADER_TAG {
    struct HEADER_TAG* ptr_next;  
    size_t bloc_size;             
    long magic_number;            
} HEADER;

static HEADER* free_list = NULL;  

void init_heap() {
    if (free_list != NULL) {
        return; 
    }

    
    void* start = sbrk(0);
    
    
    if (sbrk(INITIAL_HEAP_SIZE) == (void*) -1) {
        perror("sbrk");
        return;
    }

    free_list = (HEADER*) start;
    free_list->ptr_next = NULL;
    free_list->bloc_size = INITIAL_HEAP_SIZE - sizeof(HEADER);
    free_list->magic_number = MAGIC;

    
}
void print_free_list() {
    if (free_list == NULL) {
        printf(" Free list is empty.\n");
        return;
    }
    printf(" Free list:\n");
    printf(" Address: %p, Size: %zu bytes\n", (void*) free_list, free_list->bloc_size);
    
    }

