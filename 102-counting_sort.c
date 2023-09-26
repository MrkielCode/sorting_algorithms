#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * counting_sort - To sort an array using counting sort
 * @array: array to be sorted
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	int *counter, *dup_array, j, max_element = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_element
				)
			max_element = array[i];
	}

	counter = malloc(sizeof(int) * (max_element + 1));
	dup_array = malloc(sizeof(int) * size);
	if (counter == NULL || dup_array == NULL)
		return;

	for (j = 0; j <= max_element; j++)
		counter[j] = 0;

	for (i = 0; i < size; i++)
		counter[array[i]]++;

	for (j = 1; j <= max_element; j++)
		counter[j] = counter[j] + counter[j - 1];
	for (j = 0; j <= max_element; j++)
	{
		printf("%d", counter[j]);
		if (j != max_element)
			printf(", ");
	}
	printf("\n");
	for (j = size - 1; j >= 0; j--)
		dup_array[--counter[array[j]]] = array[j];
	for (i = 0; i < size; i++)
		array[i] = dup_array[i];

	free(counter), free(dup_array);
}
