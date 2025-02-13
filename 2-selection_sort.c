#include "sort.h"
/**
 * selection_sort - Sorting function.
 * @array: Array to srot.
 * @size: Size of array.
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	if (!array || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		if (min != j)
		{
			swap(&array[min], &array[i]);
			print_array(array, size);
		}
	}
}

/**
 * swap - funtion to swap two numbers.
 * @num1: The first number.
 * @num2: The second number.
*/
void swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}
