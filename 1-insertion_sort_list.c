#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list
* of integers in ascending order
* @list: A lisyt to bhe sorted
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *p;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;

	while (current != NULL)
	{
		temp = current->prev;
		p = current;

		while (temp != NULL && temp->n > p->n)
		{
			p->prev = temp->prev;

			if (p->prev != NULL)
			{
				p->prev->next = p;
			}

			else
			{
				*list = p;
			}

			temp->next = p->next;

			if (temp->next != NULL)
			{
				temp->next->prev = temp;
			}

			p->next = temp;
			temp->prev = p;
			temp = p->prev;

			print_list(*list);
		}

		current = current->next;
	}
}
