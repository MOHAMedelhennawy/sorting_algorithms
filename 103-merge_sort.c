#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_sort - To split the array to subarray recursively.
 * @array: The origin array.
 * @size: Size of array.
*/
void merge_sort(int *array, size_t size)
{
	size_t mid = size / 2, i;

	int *Right_array = malloc(sizeof(int) * (size - mid));
	int *Left_array = malloc(sizeof(int) * mid);

	if (!array || size < 2)
		return;

	for (i = 0; i < mid; i++)
		Left_array[i] = array[i];
	for (i = mid; i < size; i++)
		Right_array[i - mid] = array[i];

	merge_sort(Left_array, mid);
	merge_sort(Right_array, size - mid);
	merge(Right_array, Left_array, array, size - mid, mid);

	free(Left_array);
	free(Right_array);
}

/**
 * merge - To sort the array.
 * @R_array: The right side of array.
 * @L_array: The left side of array.
 * @array: The origin array.
 * @R_len: The size of right sise of subarray.
 * @L_len: The size of left size of subarray.
*/
void merge(int *R_array, int *L_array, int *array, int R_len, int L_len)
{
	int L = 0, R = 0, k = 0, i;

	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < L_len; i++)
	{
		if (i != L_len - 1)
			printf("%d, ", L_array[i]);
		else
			printf("%d\n", L_array[i]);
	}

	printf("[right]: ");
	for (i = 0; i < R_len; i++)
	{
		if (i != R_len - 1)
			printf("%d, ", R_array[i]);
		else
			printf("%d\n", R_array[i]);
	}

	while (L < L_len && R < R_len)
	{
		if (L_array[L] <= R_array[R])
		{
			array[k] = L_array[L];
			L++;
		}
		else
		{
			array[k] = R_array[R];
			R++;
		}
		k++;
	}

	while (L_len > L)
	{
		array[k] = L_array[L];
		L++;
		k++;
	}
	while (R_len > R)
	{
		array[k] = R_array[R];
		R++;
		k++;
	}
	printf("[Done]: ");
	for (i = 0; i < L + R; i++)
	{
		if (i != L + R - 1)
			printf("%d, ", array[i]);
		else
			printf("%d\n", array[i]);
	}
}
