#include "sort.h"
#include <stdlib.h>
/**
 * counting_sort - sorts an array of integers in ascending order.
 * @array: array of integers to sort.
 * @size: size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int i, j, max;
	int *count, *output;

	if (!array || size < 2)
		return;

	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = calloc((max + 1), sizeof(int));
	if (!count)
		return;
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 0, j = 0; i < max + 1; i++)
	{
		j = count[i] + j;
		count[i] = j;
	}
	print_array(count, max + 1);

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (i = 0; i < (int)size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(count);
	free(output);
}
