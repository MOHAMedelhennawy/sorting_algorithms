#include "sort.h"
/**
 * quick_sort - Sorting algorithm.
 * @array: Origin array.
 * @size: Size of array.
*/
void quick_sort(int *array, size_t size)
{

	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}
/**
 * qs - The function to sort array recursively.
 * @array: Origin array.
 * @start: The point that starts from.
 * @end: The point that will finish in.
 * @size: Size of array.
*/
void qs(int *array, int start, int end, int size)
{
	int part_index;

	if (start < end)
	{

		part_index = partition(array, start, end, size);

		qs(array, start, part_index - 1, size);
		qs(array, part_index + 1, end, size);
	}
}
/**
 * partition - The function that sort array.
 * @array: origin array.
 * @start: The point that starts from.
 * @end: The point that will finish in.
 * @size: Size of array.
 * Return: Partition index "part_index".
*/
int partition(int *array, int start, int end, int size)
{
	int pivot = array[end], i;
	int part_index = start;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(&array[i], &array[part_index]);
			part_index++;
		}
	}

	swap(&array[part_index], &array[end]);
	print_array(array, size);
	return (part_index);
}


/**
 * swap - function to swap two numbers.
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
