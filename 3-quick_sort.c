#include "sort.h"

/**
 * swap - swaps two integers.
 * @a: int
 * @b: int
 *
 * Return: Nothing
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 *partition - Partitions an array using lomuto's partition scheme
 *
 * @array: pointer to the array to be partitioned
 * @start: starting index
 * @end: ending index
 *
 * Return: i + 1
 */

int partition(int *array, int start, int end)
{
	int pivot = array[end];
	int i = start - 1;

	for (int j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[end]);
	return (i + 1);
}
/**
 *quick_sort_recursive - Recursively sorts an array
 *
 * @array: Pointer to the array to be sorted
 * @start: starting index of the partition
 * @end: ending index
 *
 *
 */

void quick_sort_recursive(int *array, int start, int end)
{
	if (start < end)
	{
		int pivot_index = partition(array, start, end);

		quick_sort_recursive(array, start, pivot_index - 1);
		quick_sort_recursive(array, pivot_index + 1, end);
	}
}
/**
 *quick_sort - Sorts an array of int in ascending order
 *
 * @array: Pointer to the array to be sorted
 * @size: Number of elements in the array
 *
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1);
}
