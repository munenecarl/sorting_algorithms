# include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
    int temp;
    size_t i, j;
    int swapped;
    size_t last_swap;

    for (i = 0; i < size - 1; i++)
    {
	swapped = 0;
	last_swap = 0;
	for (j = 0; j < size - i - 1; j++)
	{
	    if (array[j] > array[j + 1])
	    {
		temp = array[j];
		array[j] = array[j + 1];
		array[j + 1] = temp;
		swapped = 1;
		last_swap = j;
		print_array(array, size);
	    }
	}
	if (swapped == 0)
	    break;

	size = last_swap + 1;
    }
}
