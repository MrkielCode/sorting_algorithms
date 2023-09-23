#include <stdio.h>
#include "sort.h"

/**
 * swap_item - To swap items
 * @a: first item
 * @b: second item
 */

void swap_item(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * Lomuto_partition - to partition array and sort
 * @array: array of numbers
 * @upper_bound: end index of array
 * @lower_bound: first index of array
 * @size: size of the array
 * Return: pivot number
 */

int Lomuto_partition(int *array, int lower_bound, int upper_bound, size_t size)
{
	int i, j, pivot;

	/* assigning pivot to the righmost element of array */
	pivot = array[upper_bound];

	/* set i behinf the lowbound */
	i = (lower_bound - 1);

	/* looping through the array element */
	for (j = lower_bound; j < upper_bound; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swap_item(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[upper_bound])
	{
		swap_item(&array[i + 1], &array[upper_bound]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * sort - recursive sort of array
 * @array: group of numbers
 * @upper_bound: last index of array
 * @lower_bound: first index of array
 * @size: size of the array
 */

void sort(int *array, int lower_bound, int upper_bound, size_t size)
{
	int pivot;

	if (lower_bound < upper_bound)
	{
		pivot = Lomuto_partition(array, lower_bound, upper_bound, size);
		sort(array, lower_bound, pivot - 1, size);
		sort(array, pivot + 1, upper_bound, size);
	}
}
/**
 * quick_sort - to sort an array using quick sort
 * @array: array of integer numbers
 * @size: size of the arrary
 */
void quick_sort(int *array, size_t size)
{
	size_t lower_bound = 0;
	size_t upper_bound = size;

	if (array == NULL || size < 2)
		return;

	sort(array, lower_bound, upper_bound - 1, size);
}
