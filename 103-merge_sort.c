#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

void merge(int *array, size_t lower_bound, size_t mid, size_t upper_bound)
{
	int *new_array;
	size_t i = lower_bound, j = mid + 1, k = lower_bound;

	new_array = malloc(sizeof(int) * (upper_bound + lower_bound + 1));

	while (i <= mid && j <= upper_bound)
	{
		if (array[i] <= array[j])
		{
			new_array[k] = array[i];
			i++;
		}
		else
		{
			new_array[k] = array[j];
			j++;
		}
		k++;
	}
	if (i > mid)
	{
		while (j <= upper_bound)
		{
			new_array[k] = array[j];
			j++;
			k++;
		}
	}
	else
	{
		while (i <= mid)
		{
			new_array[k] = array[i];
			i++;
			k++;
		}
	}

	for (k = lower_bound; k <= upper_bound; k++)
		array[k] = new_array[k];
	
	free(new_array);

}

void sort(int *array, size_t lower_bound, size_t upper_bound)
{
	int mid;

	if (lower_bound < upper_bound)
	{
		mid = lower_bound + (upper_bound - lower_bound) / 2;
		sort(array, lower_bound, mid);
		sort(array, mid + 1, upper_bound);
		printf("Merging...\n");
		printf("[left]: ");
		printf("[right]: ");
		merge(array, lower_bound, mid, upper_bound);
	}
}

void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	sort(array, 0, size - 1);
	printf("[Done]: ");
}
