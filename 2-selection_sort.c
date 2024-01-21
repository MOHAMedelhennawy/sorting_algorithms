#include "sort.h"
/**
 * selection_sort - Sorting function.
 * @array: Array to srot.
 * @size: Size of array.
*/
void selection_sort(int *array, size_t size)
{
	int min;
	int idx = 0;
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				idx = j;
			}
		}
		swap(&array[i], &array[idx]);
		print_array(array, size);
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
