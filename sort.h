#ifndef __SORT__
#define __SORT__
#include <stddef.h>

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
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *num1, int *num2);
int partition(int low, int high, int *array, size_t size);
void qs(int *arr, int low, int high, size_t size);
listint_t *swap_node(listint_t *node, listint_t **list);
void insertion_sort_list(listint_t **list);
void shell_sort(int *array, size_t size);
#endif
