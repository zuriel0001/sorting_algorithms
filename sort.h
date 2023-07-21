#ifndef SORT_H
#define SORT_H


#include <stdio.h>
#include <stdlib.h>

/* Comparison direction macros for bitonic sort */
#define UP 0
#define DOWN 1



/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;


/**
 * enum my_bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */

typedef enum my_bool
{
	false = 0,
	true
} bool;



void print_list(const listint_t *list);
void print_array(const int *array, size_t size);

void swap_nums(int *a, int *b);
void bubble_sort(int *array, size_t size);

/**** insertion sort   ******/
void swap_list_nodes(listint_t **head, listint_t **node1, listint_t *node2);
void insertion_sort_list(listint_t **list);

/******* seletion sort   ********/
void selection_sort(int *array, size_t size);


/****** quick sort ********/
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_quicksort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);


#endif
