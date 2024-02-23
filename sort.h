#ifndef _SORT_H_
#define _SORT_H_
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap_nodes(listint_t *a, listint_t *b);
void selection_sort(int *array, size_t size);
void swap(int *array, size_t size, int *a, int *b);
size_t lomuto_partition(int *array, size_t size, ssize_t lo, ssize_t hi);
void quicksort(int *array, size_t size, ssize_t lo, ssize_t hi);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void switch_nodes(listint_t **list, listint_t **p);
void cocktail_sort_list(listint_t **list);


#endif
