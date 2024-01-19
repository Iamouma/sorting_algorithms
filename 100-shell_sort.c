#include "sort.h"
/**
 * shell_sort - sorts an array of integers.
 * @array: array to be sorted.
 * @size: size of the array.
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int len;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			len = array[i];

			for (j = i; j >= gap && array[j - gap] > len; j -= gap)
				array[j] = array[j - gap];

			array[j] = len;
		}

		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
