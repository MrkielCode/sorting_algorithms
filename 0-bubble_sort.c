#include <stdio.h>
#include "sort.h"

void bubble_sort(int *array, size_t size)
{
	int swapped_flag, temp;
	size_t i, j;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped_flag = 0;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped_flag = 1;
				print_array(array, size);
			}
		}
		if (swapped_flag == 0)
			break;
	}
}