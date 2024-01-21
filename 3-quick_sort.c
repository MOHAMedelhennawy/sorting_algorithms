#include "sort.h"

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    qs(array, 0, size - 1, size);
}

void qs(int *arr, int low, int high, size_t size)
{
    int pi;

    if (low < high)
    {
        pi = partition(low, high, arr, size);

        qs(arr, low, pi - 1, size);
        qs(arr, pi + 1, high, size);
    }
}

int partition(int low, int high, int *array, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    print_array(array, size);
    return (i + 1);
}

void swap(int *num1, int *num2)
{
    int temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
