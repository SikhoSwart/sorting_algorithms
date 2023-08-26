#include "sort.h"
/**
 * partition - scans a partition of an array of integers for values less than
 * pivot value, and swaps them with first value in partition, then swaps pivot
 * value with first value in partition
 * @array: array of integers to be sorted
 * @low: index in array that begins partition
 * @high: index in array that ends partition
 * @size: amount of elements in array
 * Return: new index at which to start new recursive partition
 */
int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot, temp;

	pivot = array[high];
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			if (array[i] != array[j])
				print_array(array, size);
			i++;
		}
	}
	temp = array[i];
	array[i] = array[high];
	array[high] = temp;
	if (array[i] != array[high])
		print_array(array, size);
	return (i);
}


/**
 * qcksort - sorts array using lomuto
 * @array: array of integers
 * @l: begins partition
 * @h: ends partition
 * @size: size of array
 * Return: nothing
 */
void qcksort(int *array, int l, int h, size_t size)
{
	int part;

	if (l < h)
	{
		part = partition(array, l, h, size);
		qcksort(array, l, part - 1, size);
		qcksort(array, part + 1, h, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using Quick sort
 * @array: array of integers
 * @size: size of array
 * Return: nothing
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
	{
		return;
	}
	qcksort(array, 0, (int)size - 1, size);
}
