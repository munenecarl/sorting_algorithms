#include "sort.h"

/**
* find_max - function to find the maximum element in the array
* @array: the array to be searched through
* @size: size of the array
* Return: int
*/

int find_max(int *array, size_t size) 
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max) 
		{
			max = array[i];
		}
	}
	return max;
}

/**
* counting_sort - performs counting sort based on specific significant digit
* @array: array to be sorted
* @size: size of the array to be sorted
* @exp: the significant digit to be used
* Return: void
*/

void counting_sort(int *array, size_t size, int exp) 
{
	int i;
	size_t j;
	int *output = (int *)malloc(size * sizeof(int));
	int count[10] = {0};

	if (output == NULL) 
	{
		printf("Memory allocation failed.\n");
		exit(1);
	}

	for (j = 0; j < size; j++) 
	{
		count[(array[j] / exp) % 10]++;
	}

	for (i = 1; i < 10; i++) 
	{
		count[i] += count[i - 1];
	}

	for (i = size - 1; i >= 0; i--) 
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (j = 0; j < size; j++)
	{
		array[j] = output[j];
	}

	free(output);
}

/**
* radix_sort - performs the radix sort on the array
* @array: array to be sorted through
* @size: size of the array to be sorted
* Return: void
*/

void radix_sort(int *array, size_t size) 
{
	int exp;
	size_t i;
	int max = find_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp);
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
}
