#include "sort.h"
#include <stdlib.h>
/**
 * counting_sort - To sort array using counting algorithm.
 * @array: origin array.
 * @size: size of array.
*/
void counting_sort(int *array, size_t size)
{
	size_t max = array[0], i;
	int *count_arr, *sorted_array;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > (int)max)
			max = array[i];

	max++;
	count_arr = malloc(sizeof(int *) * max);
	if (!count_arr)
		return;

	for (i = 0; i < max; i++)
		count_arr[i] = 0;

	for (i = 0; i < size; i++)
		count_arr[array[i]]++;

	for (i = 0; i <= max; i++)
		count_arr[i] += count_arr[i - 1];

	sorted_array = malloc(sizeof(int *) * size);
	if (!sorted_array)
		return;

	print_array(count_arr, max);
	for (i = size - 1; (int)i >= 0; i--)
	{
		count_arr[array[i]]--;
		sorted_array[count_arr[array[i]]] = array[i];
	}

	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	free(count_arr), free(sorted_array);
}
