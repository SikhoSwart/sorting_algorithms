#include "sort.h"
/**
 * selection_sort - sorts array of int in ascending order with Selection sort
 * @array: array of integers
 * @size: size of the array
 * Return: nothing
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, j, min;

	if (size < 2 || array == NULL)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
