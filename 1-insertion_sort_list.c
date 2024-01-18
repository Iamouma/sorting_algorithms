#include "sort.h"
/**
 * insertion_sort_list - inserts integers into a doubly-linked list.
 * @list: doubly linked list.
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *len, *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	len = (*list)->next;

	while (len != NULL)
	{
		current = len;

		while (current->prev != NULL && current->n < current->prev->n)
		{
			current->prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = current->prev;

			current->next = current->prev;
			current->prev = current->prev->prev;
			current->next->prev = current;

			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;

			print_list(*list);
		}

		len = len->next;
	}
}
