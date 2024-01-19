#include "sort.h"
/**
 * swap - swaps two integers.
 * @n: first integer.
 * @m: secong integer.
 * Return: Nothing
 */
void swap(int *n, int *m)
{
	int temp = *n;
	*n = *m;
	*m = temp;
}

/**
 * lomuto_partition - places pivot
 * @array: array to sort
 * @size: size of the array
 * @low: starting index
 * @high: ending index
 * Return: Index of the placed pivot
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < array[high])
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - sorts an array of integers in ascending order.
 * @array: array to be sorted.
 * @size: size of the array.
 * @low: starting index
 * @high: ending index
 * Return: Nothing.
 */
void quicksort(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, size, low, high);
		quicksort(array, size, low, pivot_index - 1);
		quicksort(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - sorts the array of integers in ascending order.
 * @array: array to be sorted.
 * @size: size of the array.
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quicksort(array, size, 0, size - 1);
}
