#include "init_chaine.h"
#include "malloc.h"
#include <stdio.h>

int main() {
    init_heap();
    init_heap_multiple(3);

    printf("Avant malloc_3is():\n");
    print_free_list();

    void* ptr1 = malloc_3is(2000);
    printf("\nAprès malloc_3is(2000):\n");
    print_free_list();

    void* ptr2 = malloc_3is(5000);
    printf("\nAprès malloc_3is(5000):\n");
    print_free_list();

    return 0;
}
