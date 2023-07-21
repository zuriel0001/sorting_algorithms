#include "sort.h"


/**
* swap_nums - function that swap two integers in an array
*
** @a: The first integer to swap.
** @b: The second integer to swap.
**/

void swap_nums(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * shell_sort - the shell sort algorithm of sorting integers in
 *                ascending order.
 *
 * @array: An array of integers to be sorted.
 * @size: The size of the array.
 *
 * Description: Uses the Knuth interval sequence.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap; /* current interval (gap) used in Shell sort */
	size_t outer_idx; /* the index used in the outer loop of Shell sort*/
	size_t inner_idx; /* the index used in the inner loop of Shell sort */

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (outer_idx = gap; outer_idx < size; outer_idx++)
		{
			inner_idx = outer_idx;
			while (inner_idx >= gap && array[inner_idx - gap] > array[inner_idx])
			{
				swap_nums(array + inner_idx, array + (inner_idx - gap));
				inner_idx -= gap;
			}
		}
		print_array(array, size);
	}
}

