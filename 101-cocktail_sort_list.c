#include "sort.h"
/**
 * cocktail_sort_list - sorts a doubly linked list of in ascending order.
 * @list: the doubly linked list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *len;
	int swap;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swap = 0;
		for (len = *list; len != NULL && len->next != NULL; len = len->next)
		{
			if (len->n > len->next->n)
			{
				swap_nodes(len, len->next, list);
				print_list(*list);
				swap = 1;
			}
		}

		if (!swap)
			break;

		swap = 0;
		for (; len->prev != NULL; len = len->prev)
		{
			if (len->prev->n > len->n)
			{
				swap_nodes(len->prev, len, list);
				print_list(*list);
				swap = 1;
			}
		}
	} while (swap);
}

/**
 * swap_nodes - swaps adjacent node of a doubly-linked list.
 * @left: pointer to left node.
 * @right: pointer to right node.
 * @list: pointer to doubly-linked list.
 */
void swap_nodes(listint_t *left, listint_t *right, listint_t **list)
{
	listint_t *swap;

	if (left->prev)
		left->prev->next = right;
	else
		*list = right;
	if (right->next)
		right->next->prev = left;
	right->prev = left->prev;
	left->prev = right;
	swap = right;
	left->next = right->next;
	swap->next = left;

	print_list(*list);
}
