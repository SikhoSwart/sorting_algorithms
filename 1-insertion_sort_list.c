#include "sort.h"
/**
 *swap - swap a node for previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	back->next = current->next;
	if (current->next)
	{
		current->next->prev = back;
	}
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
	{
		current->prev->next = current;
	}
	else
	{
		*list = current;
	}
	return (current);
}

/**
 * insertion_sort_list - sorts doubly-linked list of int, using Insertion sort
 * @list: doubly-linked list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nd;

	if (!list || (*list)->next == NULL)
	{
		return;
	}
	nd = (*list)->next;
	while (nd)
	{
		while (nd->prev && (nd->prev->n > nd->n))
		{
			nd = swap(nd, list);
			print_list(*list);
		}
		nd = nd->next;
	}
}
