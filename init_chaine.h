#ifndef INIT_CHAINE_H
#define INIT_CHAINE_H

#include <stddef.h>

typedef struct HEADER_TAG {
    struct HEADER_TAG* ptr_next;
    size_t bloc_size;
    long magic_number;
} HEADER;

// déclaration globale de free_list
extern HEADER* free_list;


void init_heap();
void print_free_list();

#endif
