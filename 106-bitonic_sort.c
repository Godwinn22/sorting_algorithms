#include "sort.h"

/**
 * bitonic_sort - a fucntion that sorts an array following the
 * Bitonic sort algorithm
 * @array: the array of ints to sort
 * @size: the size of the array
 *
 * Return: none
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_recursion(array, 0, size - 1, 1, size);
}

/**
 * bitonic_recursion - a recursive function for bitonic sort
 * @array: the array to sort
 * @l: the index of the left-most element
 * @r: the index of the right-most element
 * @path: the ascending or descending
 * @size: the size of the array
 *
 * Return: none
 */
void bitonic_recursion(int *array, int l, int r, int path, size_t size)
{
	int steps;

	if (r - l >= 1)
	{
		steps = (r + l) / 2;
		printf("Merging [%d/%lu] ", r - l + 1, size);
		if (path)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
		bitonic_recursion(array, l, steps, 1, size);
		bitonic_recursion(array, steps + 1, r, 0, size);
		bitonic_merge(array, l, r, path);
		printf("Result [%d/%lu] ", r - l + 1, size);
		if (path)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(array + l, r - l + 1);
	}
}

/**
 * bitonic_merge - a function that sorts and merges a sequence
 * in order of ascending or descending
 * @array: array to sort
 * @l: the index of the left-most element
 * @r: the index of the right-most element
 * @path: the ascending or descending order
 *
 * Return: none
 */
void bitonic_merge(int *array, int l, int r, int path)
{
	int temp, i, steps = (l + r) / 2, middle = (r - l + 1) / 2;

	if (r - l >= 1)
	{
		for (i = l; i < l + middle; i++)
		{
			if (path == (array[i] > array[i + middle]))
			{
				temp = array[i + middle];
				array[i + middle] = array[i];
				array[i] = temp;
			}
		}
		bitonic_merge(array, l, steps, path);
		bitonic_merge(array, steps + 1, r, path);
	}
}
