#include "sort.h"

/**
* swap_nums - function that swap two integers in an array
*
* @a: The first integer to swap.
* @b: The second integer to swap
*/

void swap_nums(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * heapify_max - Turn a binary tree into a complete binary heap.
 *
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array or tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */

void heapify_max(int *array, size_t size, size_t base, size_t root)
{
	size_t left; /*index of the left child of the current node*/
	size_t right; /*index of the right child of the current node*/
	size_t large; /*idx of largest ele among the current node*/
			/*and its children*/

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;

	if (right < base && array[right] > array[large])
	{
		large = right;
	}

	if (large != root)
	{
		swap_nums(array + root, array + large);
		print_array(array, size);
		heapify_max(array, size, base, large);
	}
}

/**
 * heap_sort - a function that sort an array of integers in
 *             ascending order using the heap sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort algorism
 *              Prints the array after each swap.
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (!array || size < 2)
		return;

	i = (size / 2) - 1;
	while (i >= 0)
	{
		heapify_max(array, size, size, i);
		i--;
	}

	for (i = size - 1; i > 0; i--)
	{
		swap_nums(array, array + i);
		print_array(array, size);
		heapify_max(array, size, i, 0);
	}
}
