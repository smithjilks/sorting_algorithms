#include "sort.h"

/**
 * selection_sort - sorts an array of integers in
 * ascending order using the Selection sort
 * algorithm
 *
 * @array: input array of integers
 * @size: size of the array
 * Return: no return
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min])
				min = j;

		swap(&array[i], &array[min]);

		if (i != min)
			print_array(array, size);
	}
}


/**
 * swap - swaps two integers
 *
 * @a: first parameter for the swap_int function
 * @b: second parameter for the swap_int funtion
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
