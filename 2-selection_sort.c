#include "sort.h"
/**
 * swap - swaps two integers.
 * @n: pointer to the first integer.
 * @m: pointer to the second integer.
 */
void swap(int *n, int *m)
{
	int temp = *n;
	*n = *m;
	*m = temp;
}

/**
 * selection_sort - sorts integers in ascending order.
 * @array: the array of integers.
 * @size: the size of the array.
 */
void selection_sort(int *array, size_t size)
{
	int i;
	int j;
	int min_idx;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < (int)(size - 1); i++)
	{
		min_idx = i;
		for (j = i + 1; j < (int)(size); j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			if (array[min_idx] != array[i])
			{
				swap(&array[min_idx], &array[i]);
				print_array(array, size);
			}
		}
	}
}
