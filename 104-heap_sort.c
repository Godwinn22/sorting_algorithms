#include "sort.h"

/**
 * heap_sort - a function that sorts an array following the
 * Heap sort algorithm
 * @array: the array of integers to sort
 * @size: the size of the array to sort
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int temp;

	if (size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, (size_t)i, size);

	for (i = size - 1; i >= 0; i--)
	{
		temp = array[i];
		array[i] = array[0];
		array[0] = temp;
		if (i != 0)
			print_array(array, size);
		heapify(array, (size_t)i, 0, size);
	}
}

/**
 * heapify - a function that turns an array into a heap tree
 * @array: the array to turn into a heap
 * @s: the size of the subtree
 * @root: the index of the subtree in the heap
 * @size: the size of the whole array
 *
 * Return: void
 */
void heapify(int *array, size_t s, size_t root, size_t size)
{
	size_t max, left, right;
	int temp;

	max = root;
	left = (root * 2) + 1;
	right = (root * 2) + 2;

	if (left < s && array[left] > array[max])
		max = left;

	if (right < s && array[right] > array[max])
		max = right;

	if (max != root)
	{
		temp = array[root];
		array[root] = array[max];
		array[max] = temp;
		print_array(array, size);
		heapify(array, s, max, size);
	}
}
