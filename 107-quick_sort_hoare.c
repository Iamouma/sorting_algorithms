#include "sort.h"

/**
 * swap_inte - swaps two integers in array.
 * @a: first integer to swap.
 * @b: seconf integer to swap.
 */
void swap_inte(int *a, int *b)
{
	int len;

	len = *a;
	*a = *b;
	*b = len;
}

/**
 * hoare_partition - hoare partition scheme using rightmost index.
 * @array: array of integers to sort.
 * @low: index in source array.
 * @high: index in source array.
 * @size: size of elements in array.
 * Return: new index at which to start.
 */
int hoare_partition(int *array, size_t low, size_t high, size_t size)
{
	int i, j, pivot;

	pivot = array[high];
	for (i = low - 1, j = high + 1; i < j;)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] < pivot);

		if (i < j)
		{
			swap_inte(array + i, array + j);
			print_array(array, size);
		}
	}

	return (i);
}	

/**
 * hoare_quicksort - sorts array of integers.
 * @array: array of integers to sort.
 * @low: index in source array.
 * @high: index in source array.
 * @size: size of the array.
 */
void hoare_quicksort(int *array, size_t low, size_t high, size_t size)
{
	int current;

	if (high - low > 0)
	{
		current = hoare_partition(array, size, low, high);
		hoare_quicksort(array, size, low, current - 1);
		hoare_quicksort(array, size, current, high);
	}
}

/**
 * quick_sort_hoare - sorts array of integers in ascending order.
 * @array: array of integers to print.
 * @size: size of elements in array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_quicksort(array, 0, size - 1, size);
}
