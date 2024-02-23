#include "sort.h"

/**
* shell_sort - a function that sorts an array of integers using
* the shell sort algorithm -> Knuth sequence
* @array: the array of integers
* @size: the size of the array
*
* Return: void
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, i, j;
	int temp;

	if (size < 2)
		return;

	while ((gap = gap * 3 + 1) < size)
		;

	gap = (gap - 1) / 3;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && temp <= array[j - gap]; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
