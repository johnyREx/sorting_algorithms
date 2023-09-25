#include "sort.h"
#include <stdio.h>

/**
 * getMax - Get the maximum value from an array of int.
 * @array: The array of integers
 * @size: the size of the array
 *
 * Return: The maximum value.
 */

int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	return (max);
}

/**
 * countingSort - Perform counting sort for a specific digit.
 * @size: The size of the array.
 * @array: The array to be sorted
 * @exp: The current exponent for the digit being sorted.
 */

void countingSort(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (output == NULL)
	{
		free(output);
		return;
	}

	for (i = 0; i < size; i++)
	{
		count[i] += count[i - 1];
	}

	for (i = size; i > 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}

	free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size);
	size_t exp;

	if (array == NULL || size < 2)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countingSort(array, size, exp);
		print_array(array, size);
	}
}
