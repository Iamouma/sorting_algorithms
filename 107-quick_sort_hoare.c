#include "sort.h"
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
	int i, j, pivot, len;

	pivot = array[high];
	i = low - 1;
	j = high + 1;
	while (true)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i == j)
			return (j - 1);
		else if (i > j)
			return (j);
		len = array[i];
		array[i] = array[j];
		array[j] = len;
		print_array(array, size);
	}
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
	size_t current;

	if (low < high)
	{
		current = hoare_partition(array, low, high, size);
		hoare_quicksort(array, low, current, size);
		hoare_quicksort(array, current + 1, high, size);
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
