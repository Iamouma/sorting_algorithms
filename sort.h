#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define UP 0
#define DOWN 1


/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void swap(int *n, int *m);
void selection_sort(int *array, size_t size);
int lomuto_partition(int *array, size_t size, int low, int high);
void quicksort(int *array, size_t size, int low, int high);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void swap_nodes(listint_t *left, listint_t *right, listint_t **list);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void Print_Array(int *array, int start, int end);
void Copy_Array(int *source, int start, int end, int *dest);
void TopDownMerge(int *source, int start, int cent, int end, int *dest);
void TopDownSplitMerge(int *source, int start, int end, int *dest);
void merge_sort(int *array, size_t size);
int Parent(int i);
int LeftChild(int i);
void ConvertToHeap(int *array, size_t size);
void SiftDown(int *array, size_t size, int beg, int last);
void heap_sort(int *array, size_t size);
void init_jog_count(int *jog_count);
void build_jogs(int *jog_count, int **jogs);
int get_max(int *array, size_t size);
void flat_array(int *array, size_t size, int **jogs, int *jog_count);
void radix_sort(int *array, size_t size);




#endif
