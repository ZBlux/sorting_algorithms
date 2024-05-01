#include "sort.h"

/**
* selection_sort - sorts an array of integers in ascending order.
* using Selection sort algorithm
* @array: array of integers to be sorted
* @size: size of the array
*
* Return: Nothing
*/

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int index, temp, swap;

	for (i = 0; i < size - 1; i++)
	{
		index = i;
		swap = 0;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[index])
			{
				index = j;
				swap = 1;
			}
		}

		if (swap)
		{
			temp = array[i];
			array[i] = array[index];
			array[index] = temp;

			print_array(array, size);
		}
	}
}
