#include "sort.h"

/**
* swap - swaps elements in an array
* @array: array containing elements to be swapped
* @i: first element
* @j: second element
* Return: void
*/

void swap(int *array, size_t i, size_t j) 
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
* hoare_partition - partitions the array using the hoare method
* @array: array to be partioned
* @low: low index of the partion
* @high: high index of the partion
* Return: void
*/

size_t hoare_partition(int *array, size_t low, size_t high) 
{
	int pivot = array[high];
	size_t i = low - 1;
	size_t j = high + 1;

	while (1) 
	{
		do 
		{
			i++;
		} while (array[i] < pivot);

		do 
		{
			j--;
		} while (array[j] > pivot);

		if (i >= j) 
		{
			return j;
		}

		swap(array, i, j);
	}
}

/**
* quick_sort_recursive - recursively performs the quick sort algorithm
* @array: array to be sorted
* @low: low index of the partion
* @high: high index of the partion
* Return: void
*/

void quick_sort_recursive(int *array, size_t low, size_t high) 
{
	if (low < high) 
	{
		size_t partition_index = hoare_partition(array, low, high);

		quick_sort_recursive(array, low, partition_index);
		quick_sort_recursive(array, partition_index + 1, high);
	}
}

/**
* quick_sort_hoare - entry point for the algorithm
* @array: array to be sorted
* @size: size of the array to be sorted
* Return: void
*/

void quick_sort_hoare(int *array, size_t size) 
{
	if (size <= 1)
	{
		return;
	}

	quick_sort_recursive(array, 0, size - 1);
}
