#include "sort.h"

/**
 * quick_sort - sorts the list using the quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
	return;
    quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - sorts the list using the quick sort algorithm
 * @array: array to be sorted
 * @low: low index
 * @high: high index
 * @size: size of the array
 */

void quick_sort_helper(int *array, int low, int high, size_t size)
{
    int pivot;

    if (low < high)
    {
	pivot = partition(array, low, high, size);
	quick_sort_helper(array, low, pivot - 1, size);
	quick_sort_helper(array, pivot + 1, high, size);
    }
}