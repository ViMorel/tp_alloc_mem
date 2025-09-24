#include "init_chaine.h"
#include <stdio.h>

void init_heap_multiple(); 

int main() {
    init_heap();
    printf("Après init_heap():\n");
    print_free_list();

    init_heap_multiple();
    printf("\nAprès init_heap_multiple():\n");
    print_free_list();

    return 0;
}
