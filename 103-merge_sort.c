#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Print_Array - prints array of integers for range of indicies.
 * @array: array to be printed.
 * @start: starting index value.
 * @end: ending index value.
 */
void Print_Array(int *array, int start, int end)
{
	int i;

	for (i = start; i < end; i++)
		if (i < end - 1)
			printf("%i, ", array[i]);
		else
			printf("%i\n", array[i]);
}

/**
 * Copy_Array - copy of source to dest
 * @source: array of values to sort.
 * @start: starting index value.
 * @end: ending index value.
 * @dest: array to store the sorted integers.
 */
void Copy_Array(int *source, int start, int end, int *dest)
{
	int i;

	for (i = start; i < end; i++)
		dest[i] = source[i];
}

/**
 * TopDownMerge - sorts subsections of source by ascending order.
 * @source: array of values to sort.
 * @start: left subsection starting index value.
 * @cent: right subsection starting index value.
 * @end: right subsection ending index value.
 * @dest: array to store the sorted integers.
 */
void TopDownMerge(int *source, int start, int cent, int end, int *dest)
{
	int i, j, k;

	i = start, j = cent;

	printf("Merging...\n");
	printf("[left]: ");
	Print_Array(source, start, cent);
	printf("[right]: ");
	Print_Array(source, cent, end);

	for (k = start; k < end; k++)
	{
		if (i < cent && (j >= end || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i++;
		}
		else
		{
			dest[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	Print_Array(dest, start, end);
}

/**
 * TopDownSplitMerge - splits working copy of array into subsections.
 * @source: array of integers to sort.
 * @start: starting index value.
 * @end: ending index value.
 * @dest: array to store the sorted integers.
 */
void TopDownSplitMerge(int *source, int start, int end, int *dest)
{
	int cent;

	if (end - start < 2)
		return;

	cent = (end + start) / 2;

	TopDownSplitMerge(dest, start, cent, source);
	TopDownSplitMerge(dest, cent, end, source);
	TopDownMerge(source, start, cent, end, dest);
}

/**
 * merge_sort - sorts an array of integers in ascending order.
 * @array: array of integers to be sorted.
 * @size: size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *current;

	if (!array || size < 2)
		return;

	current = malloc(sizeof(int) * size);
	if (!current)
		return;

	Copy_Array(array, 0, size, current);
	TopDownSplitMerge(current, 0, size, array);

	free(current);
}

