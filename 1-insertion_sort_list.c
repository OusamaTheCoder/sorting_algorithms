#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *swap;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		swap = current;

		while (swap->prev != NULL && swap->prev->n > swap->n)
		{
			swap->prev->next = swap->next;
			if (swap->next != NULL)
				swap->next->prev = swap->prev;

			swap->next = swap->prev;
			swap->prev = swap->prev->prev;

			if (swap->prev != NULL)
				swap->prev->next = swap;
			else
				*list = swap;

			swap->next->prev = swap;

			print_list(*list);
		}

		current = current->next;
	}
}
