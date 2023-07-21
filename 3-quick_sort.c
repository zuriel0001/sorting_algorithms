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
* lomuto_partition - The lomuto partition scheme (last element as pivot)
*                    Order a subset of an array of integers
*
* @array: The array of integers.
* @size: The size of the array.
* @left: The starting index of the subset to be ordered
* @right: The ending index of the subset to be ordered
*
* Return: The final partition index.
*/

int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot_elem; /* Pointer to the pivot element*/
	int above_idx; /* Index variables for elements above the pivot*/
	int below_idx; /* Index variables for elements below the pivot*/

	pivot_elem = array + right;
	for (above_idx = below_idx = left; below_idx < right; below_idx++)
	{
		if (array[below_idx] < *pivot_elem)
		{
			if (above_idx < below_idx)
			{
				swap_nums(array + below_idx, array + above_idx);
				print_array(array, size);
			}
			above_idx++;
		}
	}

	if (array[above_idx] > *pivot_elem)
	{
		swap_nums(array + above_idx, pivot_elem);
		print_array(array, size);
	}

	return (above_idx);
}


/**
* lomuto_quicksort - quic-sort algorithm through recursion.
*
* @array: An array of integers to be sorted.
* @size: The size of the array.
* @left: The starting index of the array partition to be ordered
* @right: The ending index of the array partition to be ordered
*
* Description: it uses the Lomuto partition scheme.
*/

void lomuto_quicksort(int *array, size_t size, int left, int right)
{
	int pivot_index; /*store the partition index */

	if (right - left > 0)
	{
		pivot_index = lomuto_partition(array, size, left, right);
		lomuto_quicksort(array, size, left, pivot_index - 1);
		lomuto_quicksort(array, size, pivot_index + 1, right);
	}
}

/**
* quick_sort - function that sort an array of integers in
*              ascending order using the quicksort algorithm.
*
* @array: An array of integers to be sorted
* @size: The size of the array.
*
* Description: Lomuto partition scheme is implented.
*              The array are printed after each swap of two elements.
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quicksort(array, size, 0, size - 1);
}

