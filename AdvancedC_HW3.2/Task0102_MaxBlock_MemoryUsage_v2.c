#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct list
{
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;

uint64_t findMaxBlock(list *head)
{
    size_t max_block;
    uint64_t address_max;
    list *tmp = head;

    address_max = tmp->address;
    max_block = tmp->size;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        if (tmp->size > max_block)
        {
            max_block = tmp->size;
            address_max = tmp->address;
        }
    }
    return address_max;
}

size_t totalMemoryUsage(list *head)
{
    list *tmp = head;
    size_t total_memory = tmp->size;

    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        total_memory += tmp->size;
    }
    return total_memory;
}

int main(void)
{
    return 0;
}
