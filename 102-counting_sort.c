#include "sort.h"

/**
 * counting_sort - a function that sorts an array with the
 * Counting sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr, *outer_arr, max, num, j, l;
	size_t i, k, m, n;

	if (size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	count_arr = malloc(sizeof(size_t) * (max + 1));
	outer_arr = malloc(sizeof(int) * size);

	for (j = 0; j <= max; j++)
		count_arr[j] = 0;
	for (k = 0; k < size; k++)
	{
		num = array[k];
		count_arr[num] += 1;
	}
	for (l = 1; l <= max; l++)
		count_arr[l] += count_arr[l - 1];
	print_array(count_arr, max + 1);
	for (m = 0; m < size; m++)
	{
		outer_arr[count_arr[array[m]] - 1] = array[m];
		count_arr[array[m]]--;
	}
	for (n = 0; n < size; n++)
		array[n] = outer_arr[n];

	free(count_arr);
	free(outer_arr);
}
