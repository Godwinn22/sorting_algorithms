#include "sort.h"

/**
 * merge_sort - a function that sorts an array using the Merge Sort algorithm
 * @array: the array of integers to sort
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *arr;

	if (!array || size < 2)
		return;

	arr = malloc(sizeof(int) * size);

	merge_recursion(arr, array, 0, size);
	free(arr);
}

/**
 * merge_recursion - a recursive function that use merge sorting
 * to sort an array
 * @arr: the copied array
 * @array: the array to sort
 * @left: the index of the left element
 * @right: the index of the right element
 */
void merge_recursion(int *arr, int *array, size_t left, size_t right)
{
	size_t center;

	if (right - left > 1)
	{
		center = (right - left) / 2 + left;
		merge_recursion(arr, array, left, center);
		merge_recursion(arr, array, center, right);
		merge_subarray(arr, array, left, center, right);
	}
}

/**
 * merge_subarray - merges subarrays
 * @arr: copy array
 * @array: array to merge
 * @left: index of the left element
 * @center: index of the center element
 * @right: index of the right element
 */
void merge_subarray(int *arr, int *array, size_t left,
		    size_t center, size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, center - left);
	printf("[right]: ");
	print_array(array + center, right - center);

	for (i = left, j = center; i < center && j < right; k++)
	{
		if (array[i] < array[j])
			arr[k] = array[i++];
		else
			arr[k] = array[j++];
	}

	while (i < center)
		arr[k++] = array[i++];
	while (j < right)
		arr[k++] = array[j++];

	for (k = left, i = 0; k < right; k++)
		array[k] = arr[i++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
