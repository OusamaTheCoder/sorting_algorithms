#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection sort algorithm.
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y, index;
	int swap;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		index = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[index])
				index = y;
		}

		if (index != x)
		{
			swap = array[x];
			array[x] = array[index];
			array[index] = swap;
			print_array(array, size);
		}
	}
}
