#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: arrray to be sorted
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_quick_sort(array, 0, size - 1, size);
}
/**
 * _quick_sort - recursive quick sort function
 *
 * @array: arrray to be sorted
 * @size: size of the array
 * @low: first element of array
 * @high: last element of array
 *
 * Return: void
 */
void _quick_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = get_pivot(array, low, high, size);
		_quick_sort(array, low, pivot - 1, size);
		_quick_sort(array, pivot + 1, high, size);
	}
}
/**
 * swap - swaps two integers
 *
 * @a: first parameter for the swap function
 * @b: second parameter for the swap funtion
 *
 * Return: void
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

/**
 * get_pivot - sorts elements less than pivot to the left
 * and elements greater than pivot to the right of pivot.
 * using the Quick sort algorithm
 *
 * @array: arrray to be sorted
 * @low: first element of array
 * @high: last element of array
 * @size: length of array
 *
 * Return: index of pivot
 */
int get_pivot(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = (low - 1);
	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}
