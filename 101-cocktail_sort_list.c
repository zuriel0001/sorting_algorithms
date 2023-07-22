#include "sort.h"


/**
* swap_Nextnode - Function for swapping a node ahead in a doubly linked list
*
* @list: A pointer to the head of a doubly-linked list.
* @tail: A pointer to the tail of the doubly-linked list.
* @current_node: pointer to the current swapping node of the
*                cocktail shaker algo.
*/

void swap_Nextnode(listint_t **list, listint_t **tail,
				listint_t **current_node)
{
	listint_t *next_node = (*current_node)->next;

	/* If the current node has a previous node, update its next pointer */
	if ((*current_node)->prev != NULL)
		(*current_node)->prev->next = next_node;

	else
		*list = next_node;

	/* Update the previous pointer of the next node */
	next_node->prev = (*current_node)->prev;

	/* Update the next pointer of the current node */
	(*current_node)->next = next_node->next;

	/* If the next node is not NULL, update its previous pointer */
	if (next_node->next != NULL)
		next_node->next->prev = *current_node;
	else
		*tail = *current_node;

	/* Update the previous pointer of the current node */
	(*current_node)->prev = next_node;

	/* Update the next pointer of the current node */
	next_node->next = *current_node;

	/* Update the current_node pointer to the new position after the swap */
	*current_node = next_node;
}


/**
* swap_Prev_node - Swap a node in a doubly-linked list of integers
*                    with the node behind it.
*
* @list: A pointer to the head of a doubly-linked list.
* @tail: A pointer to the tail of the doubly-linked list.
* @current_node: pointer to the current swapping node of the cocktail shaker
*/

void swap_Prev_node(listint_t **list, listint_t **tail,
				listint_t **current_node)
{
	listint_t *tmp = (*current_node)->prev;

	if ((*current_node)->next != NULL)
		(*current_node)->next->prev = tmp;
	else
		*tail = tmp;

	tmp->next = (*current_node)->next;
	(*current_node)->prev = tmp->prev;

	if (tmp->prev != NULL)
		tmp->prev->next = *current_node;

	else
		*list = *current_node;

	(*current_node)->next = tmp;
	tmp->prev = *current_node;
	*current_node = tmp;
}

/**
* cocktail_sort_list - Sort a doubly-linked list of integers in ascending
*                      order using the cocktail shaker algorithm.
*
* @list: A pointer to the head of a listint_t doubly-linked list.
*/

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *current_node;
	bool isSorted = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (isSorted == false)
	{
		isSorted = true;
		for (current_node = *list; current_node != tail;
				current_node = current_node->next)
		{
			if (current_node->n > current_node->next->n)
			{
				swap_Nextnode(list, &tail, &current_node);
				print_list((const listint_t *)*list);
				isSorted = false;
			}
		}

		for (current_node = current_node->prev; current_node != *list;
					current_node = current_node->prev)
		{
			if (current_node->n < current_node->prev->n)
			{
				swap_Prev_node(list, &tail, &current_node);
				print_list((const listint_t *)*list);
				isSorted = false;
			}
		}
	}
}
