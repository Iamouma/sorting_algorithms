#include "sort.h"
/**
 * Parent - returns index of parent node.
 * @i: starting index.
 * Return: index of the parent node.
 */
int Parent(int i)
{
	return ((i - 1) / 2);
}

/**
 * LeftChild - returns the index of left child.
 * @i: starting index.
 * Return: index of left child node.
 */
int LeftChild(int i)
{
	return ((2 * i) + 1);
}

/**
 * ConvertToHeap - converts array into a heap.
 * @array: array of integers.
 * @size: size of the array.
 */
void ConvertToHeap(int *array, size_t size)
{
	int beg;

	beg = Parent(size - 1);

	while (beg >= 0)
	{
		SiftDown(array, size, beg, size - 1);
		beg--;
	}
}

/**
 * SiftDown - shuffles heap.
 * @array: array of values to sort.
 * @size: size of the array.
 * @beg: starting index.
 * @last: ending index.
 */
void SiftDown(int *array, size_t size, int beg, int last)
{
	int root, swapped, len, child;

	root = beg;

	while (LeftChild(root) <= last)
	{
		child = LeftChild(root);
		swapped = root;

		if (array[swapped] < array[child])
			swapped = child;
		if (child + 1 <= last && array[swapped] < array[child + 1])
			swapped = child + 1;
		if (swapped != root)
		{
			len = array[root];
			array[root] = array[swapped];
			array[swapped] = len;
			print_array(array, size);
			root = swapped;
		}
		else
			return;
	}
}

/**
 * heap_sort - sorts array of integers in ascending order.
 * @array: array of values to sort.
 * @size: size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int end, len;

	if (!array || size < 2)
		return;

	ConvertToHeap(array, size);

	end = (int)size - 1;
	while (end > 0)
	{
		len = array[end];
		array[end] = array[0];
		array[0] = len;
		print_array(array, size);
		end--;
		SiftDown(array, size, 0, end);
	}
}
