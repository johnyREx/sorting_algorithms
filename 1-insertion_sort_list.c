#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list
* @list: Pointer to a pointer to the head of the list.
* Description: This function sorts a doubly linked list of
* integers in ascending order
* using the Insertion sort algorithm.
* It maintains a sorted sublist and inserts each
* element from the original list into its
* correct position within the sorted sublist.
*/

void insertion_sort_list(listint_t **list)
{
listint_t *current;

if (list == NULL || *list == NULL)
return;

current = *list;

while (current)
{
listint_t *sorted = NULL;
listint_t *temp;
listint_t *next = current->next;

if (sorted == NULL || sorted->n >= current->n)
{
current->next = sorted;
current->prev = NULL;
if (sorted)
sorted->prev = current;
sorted = current;
}
else
{
temp = sorted;
while (temp->next && temp->next->n < current->n)
{
temp = temp->next;
}
current->next = temp->next;
if (temp->next)
temp->next->prev = current;
temp->next = current;
current->prev = temp;
}

if (current->prev == NULL)
*list = current;
current = next;
print_list(*list);
}
}
