#include "sort.h"

/**
* lomuto_partition - Perform Lomuto partition for Quick Sort
* @array: Array to be partitioned
* @low: Starting index of the partition
* @high: Ending index of the partition
* @size: Size of the array (unused, but required by function pointer)
* Return: Index of the pivot element after partition
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot, i, j, temp;

pivot = array[high];
i = low - 1;

for (j = low; j <= high - 1; j++)
{
if (array[j] < pivot)
{
i++;
temp = array[i];
array[i] = array[j];
array[j] = temp;
if (i != j)
print_array(array, size);
}
}

temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
if (i + 1 != high)
print_array(array, size);

return (i + 1);
}

/**
* quicksort - Recursive function to perform Quick Sort
* @array: Array to be sorted
* @low: Starting index of the partition
* @high: Ending index of the partition
* @size: Size of the array (unused, but required by function pointer)
*/
void quicksort(int *array, int low, int high, size_t size)
{
int pi;

if (low < high)
{
pi = lomuto_partition(array, low, high, size);
quicksort(array, low, pi - 1, size);
quicksort(array, pi + 1, high, size);
}
}

/**
* quick_sort - Sort an array of integers in
* ascending order using Quick Sort
* @array: Array to be sorted
* @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size <= 1)
return;

quicksort(array, 0, size - 1, size);
}
