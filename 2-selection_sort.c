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
 * selection_sort - function that sorts an array of integers in ascending
 *                  order using the Selection sort algorithm
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the array after each time swap is made
 */

void selection_sort(int *array, size_t size)
{
	int *min_ele; /* Pointer to the current minimum element */
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	i = 0;
	while (i < size - 1)
	{
		min_ele = array + i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < *min_ele)
				min_ele = array + j;
			else
				min_ele = min_ele;
		}

		if ((array + i) != min_ele)
		{
			swap_nums(array + i, min_ele);
			print_array(array, size);
		}
		i++;
	}
}
