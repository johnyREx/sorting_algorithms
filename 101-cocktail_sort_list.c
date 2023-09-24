#include "sort.h"

/**
* swap_nodes - Swap two nodes in a listint_t doubly-linked list.
* @h: A pointer to the head of the doubly-linked list.
* @n1: A pointer to the first node to swap.
* @n2: The second node to swap.
*/

void swap_nodes(listint_t **h, listint_t **n1, listint_t *n2)
{
(*n1)->next = n2->next;
if (n2->next != NULL)
n2->next->prev = *n1;
n2->prev = (*n1)->prev;
n2->next = *n1;
if ((*n1)->prev != NULL)
(*n1)->prev->next = n2;
else
*h = n2;
(*n1)->prev = n2;
*n1 = n2->prev;
}

/**
* cocktail_sort_list - Sorts a doubly linked list of integers
* in ascending order using the Cocktail Shaker sort algorithm.
* @list: A pointer to the head of the doubly linked list.
*/
void cocktail_sort_list(listint_t **list)
{
int swapped;
listint_t *left, *right;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

do 
{
swapped = 0;
left = *list;
while (left->next != NULL) 
{
if (left->n > left->next->n) 
{
swap_nodes(list, &left, left->next);
swapped = 1;
print_list((const listint_t *)*list);
}
else
left = left->next;
}
if (swapped == 0)
break;

swapped = 0;
right = left;
while (right->prev != NULL) 
{
if (right->n < right->prev->n) 
{
swap_nodes(list, &right->prev, right);
swapped = 1;
print_list((const listint_t *)*list);
}
else
right = right->prev;
}
} while (swapped);
}
