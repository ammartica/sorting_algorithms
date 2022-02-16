#include "sort.h"

/**
 * quick_sort - sorts array of ints using quick sort algorithm
 * @array: array of ints to be sorted
 * @size: size of array
 *
 * Return: VOID
 */
void quick_sort(int *array, size_t size)
{
	int low = size - 1;

	if (array == NULL || size == 0)
		return;
	quickSort(array, 0, low, size);
}

/**
 * quickSort - sorts partition of array of ints
 * @array: array of ints to sort
 * @low: lowest index of partition
 * @high: highest index of partition
 * @size: size of array
 *
 * Return: VOID
 */
void quickSort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quickSort(array, low, pivot - 1, size);
		quickSort(array, pivot + 1, high, size);
	}
}

/**
 * partition - finds partition for quicksort
 * @array: array of ints to sort
 * @low: lowest index of partition
 * @high: highest index of partition
 * @size: size of array
 *
 * Return: index of partition
 */
size_t partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, size);
			}
		}
	}
	return (i);
}

/**
 * swap - swaps ints in array
 * @array: list of ints
 * @a: first element to be swapped
 * @b: second element to be swapped
 *
 * Return: VOID
 */
void swap(int *array, int a, int b)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;
}
