#include "sort.h"

/**
 * print_list - Print the elements of a doubly linked list
 * @list: Pointer to the head of the list
 *
 * Description: This function prints the elements of a doubly linked list.
 */

void print_list(const listint_t *list) 
{
    while (list) 
    {
        printf("%d", list->n);
        if (list->next)
            printf(", ");
        list = list->next;
    }
    printf("\n");
}
