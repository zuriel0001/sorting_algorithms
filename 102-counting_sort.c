#include "sort.h"

/**
 * get_max - function that get the maximum value in an array of integers.
 * @array: Array of integers.
 * @size: Size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int m, i;

	for (m = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			m = array[i];
	}

	return (m);
}

