#include "sort.h"

/**
 * swap - Swaps the positions of two elements in an array.
 * @array: The array containing the elements.
 * @item1: The index of the first element.
 * @item2: The index of the second element.
 */
void swap(int *array, ssize_t item1, ssize_t item2)
{
	int swap = array[item1];

	array[item1] = array[item2];
	array[item2] = swap;
}

/**
 * lomuto_partition - Implements the Lomuto partitioning scheme.
 * @array: The array to be partitioned.
 * @first: The index of the first element of the array.
 * @last: The index of the last element of the array.
 * @size: The size of the array.
 * Return: The position of the pivot element after partitioning.
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t current = first, finder;

	for (finder = first; finder < last; finder++)
	{
		if (array[finder] < pivot)
		{
			if (array[current] != array[finder])
			{
				swap(array, current, finder);
				print_array(array, size);
			}
			current++;
		}
	}

	if (array[current] != array[last])
	{
		swap(array, current, last);
		print_array(array, size);
	}

	return (current);
}

/**
 * quick_sort_recursive - Recursively sorts the array
  *                  using the QuickSort algorithm.
 * @array: The array to be sorted.
 * @first: The index of the first element of the array.
 * @last: The index of the last element of the array.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, ssize_t first, ssize_t last, size_t size)
{
	ssize_t position;

	if (first < last)
	{
		position = lomuto_partition(array, first, last, size);
		quick_sort_recursive(array, first, position - 1, size);
		quick_sort_recursive(array, position + 1, last, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending
 *                  order using QuickSort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
