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

/**
 * arrange_sort - Sort an array of integers in ascending order using
 * the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void arrange_sort(int *array, size_t size)
{
	int *my_count, *sort, maximum, i;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	maximum = get_max(array, size);
	my_count = malloc(sizeof(int) * (max + 1));
	if (my_count == NULL)
	{
		free(sort);
		return;
	}

	for (i = 0; i < (maximum + 1); i++)
		my_count[i] = 0;
	for (i = 0; i < (int)size; i++)
		my_count[array[i]] += 1;
	for (i = 0; i < (maximum + 1); i++)
		my_count[i] += my_count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
