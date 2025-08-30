#include "sort.h"
/**
 * bubble_sort - Sroting function.
 * @array: The origan array.
 * @size: Size of array
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size - 2; i++) {
		int swapped = 0;

		for (j = 0; j < size - 1; j++) {
			if (array[j] > array[j + 1]) {
				swapped = swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}

		if (swapped == 0) break;
	}
}

/**
 * swap - funtion to swap two numbers.
 * @num1: The first number.
 * @num2: The second number.
 * 
 * @return: 1 if swapped
*/
int swap(int *num1, int *num2)
{
	int temp;

	temp = *num1;
	*num1 = *num2;
	*num2 = temp;

	return 1;
}
