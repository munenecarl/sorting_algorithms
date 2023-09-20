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

/**
 * partition - sorts the list using the quick sort algorithm
 * @array: array to be sorted
 * @low: low index
 * @high: high index
 * @size: size of the array
 * Return: pivot
 */

int partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j, temp;

    for (j = low; j <= high - 1; j++)
    {
	if (array[j] <= pivot)
	{
	    i++;
	    temp = array[i];
	    array[i] = array[j];
	    array[j] = temp;
	    if (i != j)
	    print_array(array, size);
	}
    }
    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    if (i + 1 != j)
	print_array(array, size);
    return (i + 1);
}