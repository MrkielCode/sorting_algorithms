#include <stdio.h>
#include "sort.h"

void swap_item(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int Lomuto_partition(int *array, int lower_bound, int upper_bound, int size)
{
	int i, j, pivot;

	/* assigning pivot to the righmost element of array */
	pivot = array[upper_bound];

	/* set i behinf the lowbound */
	i = (lower_bound - 1);

	/* looping through the array element */
	for (j = lower_bound; j <= upper_bound; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_item(&array[i], &array[j]);
		}
	}
	swap_item(&array[i + 1], &array[upper_bound]);

	print_array(array, size);
	return (i + 1);
}

void sort(int *array, int lower_bound, int upper_bound, int size)
{
	int pivot;

	if (lower_bound < upper_bound)
	{
		pivot = Lomuto_partition(array, lower_bound, upper_bound, size);
		sort(array, lower_bound, pivot - 1, size);
		sort(array, pivot + 1, upper_bound, size);
	}
}

void quick_sort(int *array, size_t size)
{
	size_t lower_bound = 0;
	size_t upper_bound = size -1;
	sort(array, lower_bound, upper_bound, size);
}
