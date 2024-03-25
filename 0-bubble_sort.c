#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t x, y;
	int swap;

	if (size < 2 || array == NULL)
		return;

	for (x = 0; x < size - 1; x++)
	{
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				swap = array[y];
				array[y] = array[y + 1];
				array[y + 1] = swap;
				print_array(array, size);
			}
		}
	}
}
