#include <stddef.h>
#include "sort.h"
/**
 * bubble_sort - sorts an array of int in ascending order using Bubble sort
 * @array: array of integers
 * @size: size of the array
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, idx;
	int temp;

	if (!array || size < 2)
	{
		return;
	}
	for (i = 0; i < size; i++)
	{
		for (idx = 0; idx < size - 1; idx++)
		{
			if (array[idx] > array[idx + 1] && array[idx + 1])
			{
				temp = array[idx];
				array[idx] = array[idx + 1];
				array[idx + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
