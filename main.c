#include "init_chaine.h"
#include "malloc.h"



int main(){
    init_heap();
    print_free_list();
    
    init_heap_multiple();

    return 0;
    
    
}