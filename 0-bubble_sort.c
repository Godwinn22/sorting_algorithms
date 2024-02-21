#include "sort.h"

/**
 * bubble_sort - a function that sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;

	if (!array || !size)
	{
		return;
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
}
