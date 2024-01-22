#include "sort.h"
#include <stdio.h>
/**
 * init_jog_count - resets jog_count values to 0.
 * @jog_count: Array containing amounts of members for arrays in jog.
 */
void init_jog_count(int *jog_count)
{
	int i;

	for (i = 0; i < 10; i++)
		jog_count[i] = 0;
}

/**
 * build_jogs - allocates space for arrays to be held in jogs.
 * @jogs: array of arrays each containing sorted members of array.
 * @jog_count: array containing amounts of members for arrays in jogs.
 */
void build_jogs(int *jog_count, int **jogs)
{
	int *jog;
	int i;

	for (i = 0; i < 10; i++)
	{
		jog = malloc(sizeof(int) * jog_count[i]);
		if (!jog)
		{
			for (; i > -1; i--)
				free(jogs[i]);
			free(jogs);
			exit(EXIT_FAILURE);
		}
		jogs[i] = jog;
	}
	init_jog_count(jog_count);
}

/**
 * get_max - finds the highest value.
 * @array: array of values to search.
 * @size: size of array.
 * Return: maximum value stored in the array.
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return (max);
}

/**
 * flat_array - falttens jogs into array sorted by current digit place.
 * @array: array of values to print.
 * @size: size of the array.
 * @jogs: array of arrays containing sorted members.
 * @jog_count: array containing amounts of members for arrays in jogs.
 */
void flat_array(int *array, size_t size, int **jogs, int *jog_count)
{
	int i, j, k;

	for (k = 0, i = 0; k < 10; k++)
	{
		for (j = 0; j < jog_count[k]; j++, i++)
			array[i] = jogs[k][j];
	}

	print_array(array, size);

	for (i = 0; i < 10; i++)
		free(jogs[i]);
}

/**
 * radix_sort - sorts array of integers in ascending order.
 * @array: array of integers to sort.
 * @size: size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int **jogs;
	int jog_count[10];
	int max, max_digits, len, current, temp;
	size_t i;

	if (!array || size < 2)
		return;
	jogs = malloc(sizeof(int *) * 10);
	if (!jogs)
		exit(1);

	max = get_max(array, size);
	for (max_digits = 0; max > 0; max_digits++)
		max /= 10;

	for (len = 0, current = 1; len < max_digits; len++, current *= 10)
	{
		init_jog_count(jog_count);

		for (i = 0; i < size; i++)
		{
			temp = (array[i] / current) % 10;
			jog_count[temp]++;
		}
		build_jogs(jog_count, jogs);

		for (i = 0; i < size; i++)
		{
			temp = (array[i] / current) % 10;
			jogs[temp][jog_count[temp]] = array[i];
			jog_count[temp]++;
		}
		flat_array(array, size, jogs, jog_count);
	}
	free(jogs);
}
