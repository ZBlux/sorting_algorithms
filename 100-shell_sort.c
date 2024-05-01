#include "sort.h"

/**
*swap - the positions of two elements into an array
*@array: array
*@a: array element
*@b: array element
*/
void swap(int *array, int a, int b)
{

	int tmp;

	tmp = array[a];
	array[a] = array[b];
	array[b] = tmp;
}
/**
* shell_sort - function that sorts an array of integers in ascending
* order using the Shell sort algorithm, using the Knuth sequence
* @size: size of the array
* @array: list with numbers
*/
void shell_sort(int *array, size_t size)
{
	size_t g = 1, i, index = 0;

	if (array == NULL || size < 2)
		return;
	while (g < size / 3)
		g = 3 * g + 1;
	while (g >= 1)
	{
		for (i = g; i < size; i++)
			for (index = i; index >= g &&
					(array[index] < array[index - g]); index -= g)
				swap(array, index, index - g);
		print_array(array, size);
		g /= 3;
	}
}
