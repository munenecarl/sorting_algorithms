#include "sort.h"

/**
* swap - swaps two elements in an array
* @array: array containing the elements to be swapped
* @i: element to be swapped
* @j: element to be swapped
* Return: void;
*/

void swap(int *array, size_t i, size_t j) 
{
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
* bitonic_merge - performs bitonic merge
* @array: array to perform the merge on
* @size: size of the array
* @dir: direction to perform the merge
* Return: void
*/

void bitonic_merge(int *array, size_t size, int up)
{
	size_t i, half;

	if (size <= 1)
	{
		return;
	}

	half = size / 2;

	for (i = 0; i < half; i++)
	{
		if ((array[i] > array[i + half]) == up) 
		{
			swap(array, i, i + half);
		}
	}
}

/**
* bitonic_sort_recursive - recursively sorts an array using the bitonic method
* @array: array to be sorted
* @size: size of the array to be sorted
* @up: direction of sorting
* Return: void
*/

void bitonic_sort_recursive(int *array, size_t size, int up) {
	size_t i, half;

	if (size <= 1) 
	{
		return;
	}

	half = size / 2;

	printf("Merging [%lu/%lu] (%s):\n", size, size, up ? "UP" : "DOWN");
	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1) 
		{
			printf(", ");
		}
	}
    	printf("\n");

	bitonic_sort_recursive(array, half, 1);
	bitonic_sort_recursive(array + half, half, 0);

	bitonic_merge(array, size, up);

	printf("Result [%lu/%lu] (%s):\n", size, size, up ? "UP" : "DOWN");
	for (i = 0; i < size; i++) 
	{
		printf("%d", array[i]);
		if (i < size - 1) 
		{
			printf(", ");
		}
	}
    	printf("\n");
}

/**
* bitobic_sort - performs the bitonic sort
* @array: array to be sorted
* @size: size of the array to be sorted 
*/

void bitonic_sort(int *array, size_t size) 
{
	bitonic_sort_recursive(array, size, 1);
}
