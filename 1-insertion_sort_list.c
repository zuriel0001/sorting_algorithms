#include "sort.h"

/**
 * swap_list_nodes - a function that swap two nodes in a listint_t
 *                   doubly-linked list.
 *
 * @head : A pointer to the first node of the doubly-linked list.
 * @node1: A pointer to the first node to be swapped
 * @node2: The second node to be swapped
 */

void swap_list_nodes(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;

	if (!(!node2->next))
		node2->next->prev = *node1;

	node2->prev = (*node1)->prev;
	node2->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 *
 * @list: A pointer to the head of a doubly-linked list
 *
 * Description: the function is expected to print the list after
 *              each time you swap two element
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current; /* Points to the current node being processed*/
	listint_t *insert; /*Points to the node before the current node*/
	listint_t *tmp; /*pointer to keep track of the next node during iteration*/

	if (!list || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		insert = current->prev;
		/**
		 * Move the current node to its sorted position in
		 * the list by swapping with the previous nodes
		 */
		while (insert != NULL && current->n < insert->n)
		{
			/* Perform the swap between current and insert nodes*/
			swap_list_nodes(list, &insert, current);

			/* Print the updated list after each swap*/
			print_list((const listint_t *)*list);
		}
	}
}

