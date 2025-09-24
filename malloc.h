#ifndef MALLOC_H
#define MALLOC_H

#include <stddef.h>
#include "init_chaine.h"

void* malloc_3is(size_t size);

void init_heap_multiple(int nb_blocks);

#endif
