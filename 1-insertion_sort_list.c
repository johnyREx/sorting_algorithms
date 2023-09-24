#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list
* of integers in ascending order
* @list: A pointer to the head of the doubly linked list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *tmp;
	
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	
	current = (*list)->next;
	
	while (current)
	{
		temp = current->next;
		
		while (current-> && current-> < current->prev->n)
		{
			prev = current->prev;
			prev->next = current->next;
			
			if (current->next)
				current->next->prev = prev;
			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;
			
			if (current->prev)
				current->prev->next = current;
			
			else
				
				*list = current;
			
			print_list(*list);
		}
		
		current = temp;
	}
}
