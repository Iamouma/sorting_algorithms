#include "sort.h"

void swap_inte(int *a, int *b);
void bitonic_merge(int *array, size_t size, size_t beg, size_t cent, char end);
void bitonic_cent(int *array, size_t size, size_t beg, size_t cent, char end);
void bitonic_sort(int *array, size_t size);
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
 * bitonic_merge - sorts an array of integers.
 * @array: array of integers.
 * @size: size of the array.
 * @beg: starting index.
 * @cent: size of the sequence to sort.
 * @end: direction to sort in.
 */
void bitonic_merge(int *array, size_t size, size_t beg, size_t cent, char end)
{
	size_t i, current = cent / 2;

	if (cent > 1)
	{
		for (i = beg; i < beg + current; i++)
		{
			if ((end == UP && array[i] > array[i + current]) ||
				(end == DOWN && array[i] < array[i + current]))
				swap_inte(array + i, array + i + current);
		}
		bitonic_merge(array, size, beg, current, end);
		bitonic_merge(array, size, beg + current, current, end);
	}
}

/**
 * bitonic_cent - converts an array of integers into a bitonic sequence.
 * @array: array of integers.
 * @size: size of the array.
 * @beg: starting index.
 * @cent: size of a block.
 * @end: direction to sort.
 */
void bitonic_cent(int *array, size_t size, size_t beg, size_t cent, char end)
{
	size_t temp = cent / 2;
	char *str = (end == UP) ? "UP" : "DOWN";

	if (cent > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", cent, size, str);
		print_array(array + beg, cent);

		bitonic_cent(array, size, beg, temp, UP);
		bitonic_cent(array, size, beg + temp, temp, DOWN);
		bitonic_merge(array, size, beg, cent, end);

		printf("Result [%lu/%lu] (%s):\n", cent, size, str);
		print_array(array + beg, cent);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order.
 * @array: array of integers.
 * @size: size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_cent(array, size, 0, size, UP);
}
