#ifndef MEM_H
#define MEM_H

#include "../cpu/types.h"
#include "mybool.h"

void memory_copy(u8 *source, u8 *dest, int nbytes);
void memory_set(u8 *dest, u8 val, u32 len);

/* At this stage there is no 'free' implemented. */
u32 kmalloc(u32 size, int align, u32 *phys_addr);

typedef struct node {
    unsigned int base_address;
    unsigned int limit_offset;
    struct node* next;
    struct node* previous;
} node;

void add_node(node** head, unsigned int base_address, unsigned int limit_offset);

void delete_node(node** head, node* node_to_delete);

void resize_node(node** head, node* node_to_resize, unsigned int new_base_address, unsigned int new_limit_offset);

node* find_node(node* head, unsigned int search_address);

void sort_by_id(node** head);

void sort_by_size(node** head, bool smallest_to_largest);

#endif