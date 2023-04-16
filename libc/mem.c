#include "mem.h"

void memory_copy(u8 *source, u8 *dest, int nbytes) {
    int i;
    for (i = 0; i < nbytes; i++) {
        *(dest + i) = *(source + i);
    }
}

void memory_set(u8 *dest, u8 val, u32 len) {
    u8 *temp = (u8 *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}

u32 free_mem_addr = 0x10000;
/* Implementation is just a pointer to some free memory which
 * keeps growing */

u32 kmalloc(u32 size, int align, u32 *phys_addr) {
    /* Pages are aligned to 4K, or 0x1000 */
    if (align == 1 && (free_mem_addr & 0xFFFFF000)) {
        free_mem_addr &= 0xFFFFF000;
        free_mem_addr += 0x1000;
    }
    /* Save also the physical address */
    if (phys_addr) *phys_addr = free_mem_addr;

    u32 ret = free_mem_addr;
    free_mem_addr += size; /* Remember to increment the pointer */
    return ret;
}
/*
// Search list for a given base address
node* find(node* head, unsigned int search_address) {
    node* current = head;
    while (current != 0) {
        if (current->base_address == search_address) {
            return current;
        }
        current = current->next;
    }
    return 0;
}

// Sort list by base address
void sort_by_id(node** head) {
    node *current = *head, *index = 0;
    unsigned int temp_base, temp_limit;
    if (head == 0) {
        return;
    }
    else {    new_node->base_address = base_address;
    new_node->limit_offset = limit_offset;
    new_node->next = 0;
    new_node->previous = 0;

    if (*head == 0){
        *head = new_node;
        return;
    }
    else if (new_node->base_address < (*head)->base_address) {
        new_node->next = *head;
        (*head)->previous = new_node;
        *head = new_node;
        return;
    }
    else {
        node* current = *head;
    }
        while (current != 0) {
            index = current->next;
            while (index != 0) {
                if (current->base_address > index->base_address) {
                    temp_base = current->base_address;
                    temp_limit = current->limit_offset;
                    current->base_address = index->base_address;
                    current->limit_offset = index->limit_offset;
                    index->base_address = temp_base;
                    index->limit_offset = temp_limit;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

// Sort list by limit offset
void sort_by_size(node** head, bool smallest_to_largest) {
    node *current = *head, *index = 0;
    unsigned int temp_base, temp_limit;
    if (head == 0) {
        return;
    }
    else {
        while (current != 0) {
            index = current->next;
            while (index != 0) {
                if (smallest_to_largest) {
                    if (current->limit_offset > index->limit_offset) {
                        temp_base = current->base_address;
                        temp_limit = current->limit_offset;
                        current->base_address = index->base_address;
                        current->limit_offset = index->limit_offset;
                        index->base_address = temp_base;
                        index->limit_offset = temp_limit;
                        }
            current = current->next;
        }
    }
}

// Add a new node to the list in the correct sorted position
void add_node(node** head, unsigned int base_address, unsigned int limit_offset) {
    node* new_node = (node*)kmalloc(sizeof(node), 1, free_mem_addr);
}

// Delete a node from the list by its base address

void delete_by_address(node** head, unsigned int delete_address) {
    node* current = *head;
    while (current != 0 && current->base_address != delete_address) {
        current = current->next;
    }
    if (current == 0) {
        return;
    }
    if (current->previous != 0) {
        current->previous->next = current->next;
    } else {
        *head = current->next;
    }
    if (current->next != 0) {
        current->next->previous = current->previous;
    }
}

// Modify a node in the list by its base address and resort the list by base address
void resize(node** head, unsigned int base_address, unsigned int limit_offset) {
    node* current = *head;
    while (current != 0 && current->base_address != base_address) {
        current = current->next;
    }
    if (current == 0) {
        return;
    }
    current->limit_offset = limit_offset;
    // Resort list by base address
    sort_by_id(head);
}
*/