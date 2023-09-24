#include "sort.h"

/**
 * selection_sort - Selection sort
 *
 * @array: Array to be sorted
 * @size: size of the array to be sorted
 *
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != i)
		{
			int temp = array[i];
			array[i] = array[min];
			array[min] = temp;

			print_array(array, size);
		}
	}
}
