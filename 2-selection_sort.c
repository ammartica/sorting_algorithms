#include "sort.h"

/**
 * selection_sort - sorts array of ints using selection sort algorithm
 * @array: array of ints to be sorted
 * @size: size of the array
 *
 * Return: VOID
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, cur, swap;

	if (!array || !size)
		return;

	for (i = 0; i < size - 1; i++)
	{
		cur = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[cur] > array[j])
				cur = j;
		}
		if (i != cur)
		{
			swap = array[i];
			array[i] = array[cur];
			array[cur] = swap;
			print_array(array, size);
		}
	}
}
