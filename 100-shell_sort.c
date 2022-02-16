#include "sort.h"

/**
 * shell_sort - sorts array using Shell sort algorithm and Knuth sequence
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t in, out, gap = 1;
	int temp = 1;

	if (size < 2)
		return;
	while (gap <= size / 3)
	{
		gap *= 3 + 1;
	}
	while (gap > 0)
	{
		for (out = gap; out < size; out++)
		{
			temp = array[out];
			in = out;

			while (in > gap - 1 && array[in - gap] >= temp)
			{
				array[in] = array[in - gap];
				in -= gap;
			}
			array[in] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
