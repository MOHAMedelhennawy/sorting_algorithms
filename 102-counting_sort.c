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
	int *count;
	int *sorted_array;

	if (!array || size < 2)
		return;

	for (i = 1; i < size; i++)
	{
		if (array[i] > (int)max)
			max = array[i];
	}

	count = (int *)malloc(sizeof(int) * max);
	if (!count)
		return;

	for (i = 0; i <= max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	sorted_array = (int *) malloc(sizeof(int) * size);
	if (!sorted_array)
		return;
	print_array(count, max + 1);
	for (i = size - 1; (int)i >= 0; i--)
	{
		count[array[i]]--;
		sorted_array[count[array[i]]] = array[i];
	}

	for (i = 0; i < size; i++)
		array[i] = sorted_array[i];

	free(count), free(sorted_array);
}
