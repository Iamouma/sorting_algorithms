#include "sort.h"
#include <stdio.h>
/**
 * bit_comp - sorts contents of current subarray.
 * @up: sort in ascending order.
 * @a: subarray in current frame of recurssion.
 * @size: size of a.
 */
void bit_comp(bool up, int *a, size_t size)
{
	size_t len, i;
	int current;

	len = size / 2;
	for (i = 0; i < len; i++)
	{
		if ((a[i] > a[i + len]) == up)
		{
			current = a[i];
			a[i] = a[i + len];
			a[i + len] = current;
		}
	}
}

/**
 * bit_merge - sorts subarrays via bit_comp.
 * @up: sort in ascending order.
 * @a: subarray in previous frame of recursion.
 * @size: size of a.
 * @original_size: number of elements in source array being sorted.
 */
void bit_merge(bool up, int *a, size_t size, size_t original_size)
{
	int *first, *second;

	if (size > 1)
	{
		first = a;
		second = a + (size / 2);
		bit_comp(up, a, size);
		bit_merge(up, first, size / 2, original_size);
		bit_merge(up, second, size / 2, original_size);
	}
}

/**
 * bitonic_sort_d - divides array into a binary tree of subarrays.
 * @up: sort in ascending order.
 * @a: subarray in previous frame of recursion.
 * @size: size of a.
 * @original_size: number of elements in source array being sorted.
 */
void bitonic_sort_d(bool up, int *a, size_t size, size_t original_size)
{
	int *first, *second;

	if (size <= 1)
		return;
	first = a;
	second = a + (size / 2);
	printf("Merging [%lu/%lu] (%s):\n", size, original_size,
		(up ? "UP" : "DOWN"));
	print_array(a, size);
	bitonic_sort_d(true, first, size / 2, original_size);
	bitonic_sort_d(false, second, size / 2, original_size);
	bit_merge(high, first, size, original_size);
	printf("Result [%lu/%lu] (%s):\n", size, original_size,
		(up ? "UP" : "DOWN"));
	print_array(a, size);
}

/**
 * bitonic_sort - sorts array of integers in ascending order.
 * @array: array of values to print.
 * @size: size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;

	bitonic_sort_d(true, array, size, size);
}