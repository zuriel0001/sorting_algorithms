#include "sort.h"

/**
* swap_nums - function that swaps two integers in an array
*
* @a: The first integer to swap.
* @b: The second integer to swap.
*/

void swap_nums(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * bubble_sort - function that sorts an array of integers in ascending order
 *
 * @array: Array of integers to be sorted
 * @size: The size of the array.
 *
 * Description: The array after are to be printed after each swap
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool isSorted; /*determines if any swaps were made during a pass*/

	/*Check for invalid input or if the array is already sorted*/
	if (array == NULL || size < 2)
		return;

	/*The main loop that continues until the array is sorted*/
	isSorted = false;
	while (isSorted == false)
	{
		isSorted = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_nums(array + i, array + i + 1);
				print_array(array, size);
				isSorted = false;
			}
		}
		len--;
	}
}

