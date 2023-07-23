#include "sort.h"


/**
 * merge_subarray - Function thar Sort a subarray of integers.
 *
 * @subarr: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: front index of the array.
 * @mid:  middle index of the array.
 * @back: back index of the array.
 */

void merge_subarray(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t a, b, c = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (a = front, b = mid; a < mid && b < back; c++)
		buff[c] = (subarr[a] < subarr[b]) ? subarr[a++] : subarr[b++];
	for (; a < mid; a++)
		buff[c++] = subarr[a];
	for (; b < back; b++)
		buff[c++] = subarr[b];
	for (a = front, c = 0; a < back; a++)
		subarr[a] = buff[c++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * recursive_merge_sort - function that implement the merge sort algorithm
 *                        through recursion.
 *
 * @subarr: A subarray of an array of integers to sort.
 * @buff: buffer to store the sorted result.
 * @front:front index of the subarray.
 * @back: back index of the subarray.
 */

void recursive_merge_sort(int *subarr, int *buff, size_t front, size_t back)
{
	size_t m;

	if (back - front > 1)
	{
		m = front + (back - front) / 2;
		recursive_merge_sort(subarr, buff, front, m);
		recursive_merge_sort(subarr, buff, m, back);
		merge_subarray(subarr, buff, front, m, back);
	}
}

/**
 * merge_sort - function that sorts an array of integers in ascending
 *              order using the merge sort algorithm.
 *
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: print the array after each time you swap two elements
 *              Implements the top-down merge sort algorithm.
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	recursive_merge_sort(array, buff, 0, size);

	free(buff);
}
