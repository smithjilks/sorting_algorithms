#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;
	listint_t *tmp_node;

	if (list == NULL)
		return;

	node = *list;

	while (node != NULL)
	{
		while (node->next && (node->n > node->next->n))
		{
			tmp_node = node->next;
			node->next = tmp_node->next;
			tmp_node->prev = node->prev;

			if (node->prev != NULL)
				node->prev->next = tmp_node;

			if (tmp_node->next != NULL)
				tmp_node->next->prev = node;

			node->prev = tmp_node;
			tmp_node->next = node;

			if (tmp_node->prev)
				node = tmp_node->prev;
			else
				*list = tmp_node;

			print_list(*list);
		}
		node = node->next;
	}
}
