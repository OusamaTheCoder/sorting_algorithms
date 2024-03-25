#include "sort.h"

/**
 * swap - Swaps the positions of two elements in an array.
 * @array: The array containing the elements.
 * @item1: The index of the first element.
 * @item2: The index of the second element.
 */
void swap(int *array, int item1, int item2)
{
	int swap = array[item1];

	array[item1] = array[item2];
	array[item2] = swap;
}

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *              the Shell sort algorithm with Knuth sequence.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, x, y;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = 3 * gap + 1;

	while (gap >= 1)
	{
		for (x = gap; x < size; x++)
		{
			for (y = x; y >= gap && array[y] < array[y - gap]; y -= gap)
			{
				swap(array, y, y - gap);
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
