#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * swap_next - swap the current
 * @list: head pointer
 * @current: current to be swapperd
 */
void swap_next(listint_t **list, listint_t *current)
{
	listint_t *left, *right;

	left = current->prev;

	right = current->next->next;

	if (left)
		left->next = current->next;
	else
		*list = current->next;

	current->next->prev = left;
	current->prev = current->next;
	current->next = right;

	if (right)
		right->prev = current;

	current->prev->next = current;
}

/**
 * swap_prev - Swaps previous node
 * @list: head pointer
 * @current: urrent node to be swapped.
 */
void swap_prev(listint_t **list, listint_t *current)
{
	listint_t *right, *left;
       	right = current->next;
	left = current->prev->prev;

	if (left)
		left->next = current;
	else
		*list = current;

	current->prev->next = right;
	current->next = current->prev;
	current->prev = left;

	if (right)
		right->prev = current;
	current->next->prev = current;
}

/**
 * cocktail_sort_list - list to be sorted
 * @list: head pointer
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		current = *list;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_next(list, current);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->next;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		current = current->prev;

		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_prev(list, current);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				current = current->prev;
			}
		}
	}
	while (swapped);
}
