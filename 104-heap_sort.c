#include "sort.h"

/**
* heap_enforcer - function that keeps the root as the largest node
* @array: array to be sorted
* @size: size of the array to be sorted
* @root: index of the root node
* Return: void
*/

void heap_enforcer(int *array, size_t size, size_t root) {
	int temp;
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < size && array[left] > array[largest]) 
	{
		largest = left;
	}

	if (right < size && array[right] > array[largest]) 
	{
		largest = right;
	}

	if (largest != root) 
	{
		temp = array[root];
		array[root] = array[largest];
		array[largest] = temp;
		heap_enforcer(array, size, largest);
	}
}

/**
* heap_sort - performs heap sort on the array
* @array: array to be sorted
* @size: size of the array to be sorted
* Return: void
*/

void heap_sort(int *array, size_t size) {
	int i, temp;

	for (i = size / 2 - 1; i >= 0; i--) 
	{
		heap_enforcer(array, size, i);
	}
	for (i = size - 1; i >= 0; i--) 
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heap_enforcer(array, i, 0);
	}
}
