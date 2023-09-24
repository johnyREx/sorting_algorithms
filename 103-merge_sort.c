#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * copy - to Copy Data From One Buffer To Another.
 *
 * @src: Source Buffer.
 *
 * @dst: Destination Buffer.
 *
 * @size: Size Of Buffers.
 * Return: no return
 */

void copy(int *src, int *dst, int size)
{
	int i;

	for (i = 0; i < size; i++)
		dst[i] = src[i];
}

/**
 * merge - to Merge 2 Sets Of Data In Ascending Order.
 *
 * But They Must Be Sorted Before Hand.
 *
 * @array: 1st Set Of Data.
 *
 * @buff: 2nd Set Of Data.
 *
 * @minL: Lower Range Of 1st Set Of Data.
 *
 * @maxL: Upper Range Of 1st Set Of Data.
 *
 * @minR: Lower Range Of 2nd Set Of Data.
 *
 * @maxR: Upper Range Of 2nd Set Of Data
 * Return: No Return
 */

void merge(int *array, int *buff, int minL, int maxL, int minR, int maxR)
{
	int i = minL, j = minR, k = minL;

	while (i <= maxL || j <= maxR)

		if (i <= maxL && j <= maxR)
			if (buff[i] <= buff[j])
				array[k] = buff[i], k++, i++;
			else
				array[k] = buff[j], k++, j++;

		else if (i > maxL && j <= maxR)
			array[k] = buff[j], k++, j++;
		else
			array[k] = buff[i], k++, i++;
}

/**
 * printcheck - to Print the Array In the Given Range.
 * @array: an array Of Data To Be Print.
 *
 * @r1: to Start Of Range.
 *
 * @r2: End Of Range.
 * Return: no return
 */

void printcheck(int *array, int r1, int r2)
{
	int i;

	for (i = r1; i <= r2; i++)
	{
		if (i > r1)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * split - a recursive Function To Split Data Into Merge Tree.
 * @array: an array Of Data To Be Split.
 *
 * @buff: Auxiliary Array Of Data For Merging.
 *
 * @min: Minimunm Range Of Data In an array.
 *
 * @max: Maximum Range Of Data In an array.
 *
 * @size: the Size Of Total Data.
 * Return: no return
 */

void split(int *array, int *buff, int min, int max, int size)
{
	int mid, tmax, minL, maxL, minR, maxR;

	if ((max - min) <= 0)
		return;

	mid = (max + min + 1) / 2;
	tmax = max;
	max = mid - 1;

	minL = min;
	maxL = max;

	split(array, buff, min, max, size);

	min = mid;
	max = tmax;

	minR = min;
	maxR = max;

	split(array, buff, min, max, size);

	printf("Merging...\n");
	printf("[left]: ");

	printcheck(array, minL, maxL);

	printf("[right]: ");

	printcheck(array, minR, maxR);
	merge(array, buff, minL, maxL, minR, maxR);
	copy(array, buff, size);

	printf("[Done]: ");
	printcheck(array, minL, maxR);
}

/**
 * merge_sort - to Sort the Array Of Int In ascending Order.
 *
 * Using a merge Sort Algorithm
 * @array: an array Of the Data To Be Sorted.
 *
 * @size: the Size Of Data.
 * Return: no return
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	copy(array, buff, size);

	split(array, buff, 0, size - 1, size);

	free(buff);
}
