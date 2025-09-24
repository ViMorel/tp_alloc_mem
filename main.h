#include <stdlib.h>

#define magic 0x0123456789ABCDEFL

typedef struct header_tag{
    struct header_tag * ptr_next;
    size_t block_size;
    long magic_number;
} header;


header free_space_list = {nullptr, 4096, magic};
header used_space_list = {};