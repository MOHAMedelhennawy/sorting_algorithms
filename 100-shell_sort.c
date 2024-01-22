#include "sort.h"

void shell_sort(int *array, size_t size)
{
    size_t gap, i, j;

    for (gap = 1; gap < size / 3; gap = 3 * gap + 1);

    while (gap > 0)
    {
        for (i = gap; i < size; i++)
        {
            for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
            {
                swap(&array[j - gap], &array[j]);
            }
        }

        print_array(array, size);
        gap = (gap - 1) / 3;
    }
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
