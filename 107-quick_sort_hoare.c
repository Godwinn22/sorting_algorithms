#include "sort.h"

/**
 * quick_sort_hoare - a function that sorts an array with the
 * Quicksort algorithm
 * @array: the array of ints to sort
 * @size: the size of the array
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_recursion(array, 0, (int)size - 1, size);
}

/**
 * quick_recursion - a helper function for Quicksorting
 * @array: the array to sort
 * @left:  the index of the left element
 * @right: the index of the right element
 * @size: the size of the array
 *
 * Return: void
 */
void quick_recursion(int *array, int left, int right, size_t size)
{
	int pivot_index;

	if (left < right)
	{
		pivot_index = partition(array, left, right, size);
		quick_recursion(array, left, pivot_index - 1, size);
		quick_recursion(array, pivot_index, right, size);
	}
}

/**
 * partition - a function that gives a pivot_index index for
 * Quicksorting
 * @array: the array to find the pivot_index in
 * @left: the index of the left element
 * @right: the index of the right element
 * @size: the size of the array
 *
 * Return: returns the index of the pivot_index element
 */
int partition(int *array, int left, int right, size_t size)
{
	int temp, pivot_indexot = array[right];
	size_t i, j;

	i = left - 1;
	j = right + 1;
	while (1)
	{
		do
		{
			i++;
		} while (array[i] < pivot_indexot);
		do
		{
			j--;
		} while (array[j] > pivot_indexot);
		if (i >= j)
			return (i);
		if (i != j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	return (0);
}
