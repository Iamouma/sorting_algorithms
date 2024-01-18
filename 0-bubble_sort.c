#include "sort.h"
#include <stddef.h>
#include <string.h>
/**
 * bubble_sort - Sorts an array of integers in ascending order.
 * @array: The array of integers.
 * @size: Size of the array.
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t j;
	size_t tmp;
	int len;

	if (size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		len = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				len = 1;
				print_array(array, size);
			}
		}
		if (!len)
		{
			break;
		}
	}
}
