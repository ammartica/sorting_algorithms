#include "sort.h"

/**
 * insertion_sort_list - sorts list of ints using insertion sort
 * @list: pointer to pointer to list of ints
 *
 * Return: VOID
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nextN, *left, *right;

	if (list == NULL || *list == NULL)
		return;

	nextN = (*list)->next;

	while (nextN)
	{
		left = nextN->prev;
		right = nextN;
		nextN = right->next;
		while (left && left->n > right->n)
		{
			if (left->prev == NULL)
				*list = right;
			else
				left->prev->next = right;
			if (right->next)
				right->next->prev = left;
			right->prev = left->prev;
			left->next = right->next;
			left->prev = right;
			right->next = left;
			print_list(*list);
			left = right->prev;
		}
	}
}
