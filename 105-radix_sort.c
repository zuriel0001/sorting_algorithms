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

	m = array[0];
	i = 1;

	while (i < size)
	{
		if (array[i] > m)
			m = array[i];
		i++;
	}

	return (m);
}

/**
 * count_sort_alg - a function that sort the significant digits of an
 *                       array of integers in ascending order using the
 *                       counting sort algorithm.
 *
 * @array: An array of integers to be sorted
 * @size: The size of the array to he sorted
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */

void count_sort_alg(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0};
	size_t idx;

	idx = 0;
	/*count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};*/

	while (idx < size)
	{
		count[(array[idx] / sig) % 10] += 1;
		idx++;
	}

	for (idx = 0; idx < 10; idx++)
		count[idx] += count[idx - 1];

	for (idx = size - 1; (int)idx >= 0; idx--)
	{
		buff[count[(array[idx] / sig) % 10] - 1] = array[idx];
		count[(array[idx] / sig) % 10] -= 1;
	}

	idx = 0;
	while (idx < size)
	{
		array[idx] = buff[idx];
		idx++;
	}
}

/**
 * radix_sort - a function that sort an array of integers in ascending
 *              order using the radix sort algorithm.
 *
 * @array: An array of integers to he sorted
 * @size: The size of the array to be sorted
 *
 * Description: LSD radix sort algorithm is implemented
 *              Prints the array after each significant digit increase.
 */

void radix_sort(int *array, size_t size)
{
	int max_num, sig, *buff;

	if (!array || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (!buff)
		return;

	max_num = get_max(array, size);
	for (sig = 1; max_num / sig > 0; sig *= 10)
	{
		count_sort_alg(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
