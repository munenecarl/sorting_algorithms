# include "sort.h"

/**
 * insertion_sort_list - sorts the list using the insertion sort algorithm
 * @list: list to be sorted
 * Return: void 
*/

void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;
    if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;

    current = (*list)->next;
    while (current != NULL)
    {
	temp = current->next;
	while (current->prev != NULL && current->n < current->prev->n)
	{
	    current->prev->next = current->next;
	    if (current->next != NULL)
		current->next->prev = current->prev;
	    current->next = current->prev;
	    current->prev = current->prev->prev;
	    current->next->prev = current;
	    if (current->prev == NULL)
		*list = current;
	    else
		current->prev->next = current;
	    print_list(*list);
	}
	current = temp;
    }
}


/**
 * insertion_sort - similar impelemtation if it were an array
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void insertion_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int temp;
    size_t i, j;

    for (i = 1; i < size; i++)
    {
        temp = array[i];
        j = i;

        while (j > 0 && temp < array[j - 1])
        {
            array[j] = array[j - 1];
            j--;
        }

        array[j] = temp;
    }
}
