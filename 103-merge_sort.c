#include "sort.h"

/**
* merge - function that merges two arrays
* @array: array to be merged
* @temp: temporary placeholder for the array being sorted
* @left_start: start of thee left array
* @left_end: end of the left array
* @right_start: start of the right array
* @right_end: end of the right array 
* Return: void
*/

void merge(int *array, int *temp, size_t left_start, size_t left_end, size_t right_start, size_t right_end) 
{
	
	size_t i;
	size_t left_size = left_end - left_start + 1;
	size_t right_size = right_end - right_start + 1;

	size_t left_index = left_start, right_index = right_start, temp_index = 0;

	while (left_index <= left_end && right_index <= right_end) 
	{
		if (array[left_index] <= array[right_index]) 
		{
			temp[temp_index++] = array[left_index++];
		} 
		else 
		{
			temp[temp_index++] = array[right_index++];
		}
	}
	while (left_index <= left_end) 
	{
		temp[temp_index++] = array[left_index++];
	}
	while (right_index <= right_end) 
	{
		temp[temp_index++] = array[right_index++];
	}
	for (i = 0; i < left_size + right_size; i++)
	{
		array[left_start + i] = temp[i];
	}
}

/**
* merge_sort_recursive - function that recursively sorts the array
* @array: array to be sorted
* @temp: temorary placeholder array
* @left: left array 
* @right: right array
* Return: Void
*/

void merge_sort_recursive(int *array, int *temp, size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;

        merge_sort_recursive(array, temp, left, mid);
        merge_sort_recursive(array, temp, mid + 1, right);

        merge(array, temp, left, mid, mid + 1, right);
    }
}

/**
* merge_sort: function that actualizes the merge sort algorithm
* @array: array to be sorted
* @size: size of thw array to be sorted
* Return: void
*/

void merge_sort(int *array, size_t size)
{
	int *temp;
	if (size <= 1) 
	{
		return; 
	}

	temp = (int *)malloc(size * sizeof(int));

	if (temp == NULL) 
	{
		printf("Memory allocation failed.\n");
		exit(1);
	}

	merge_sort_recursive(array, temp, 0, size - 1);
	free(temp);
}