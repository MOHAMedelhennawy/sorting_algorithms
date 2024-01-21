#include "sort.h"

void selection_sort(int *array, size_t size)
{
    int min, temp;
    int idx = 0;
    size_t i, j;

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
        temp = array[i];
        array[i] = min;
        array[idx] = temp;
        print_array(array, size);
    }
}