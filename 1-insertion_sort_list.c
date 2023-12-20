#include "sort.h"

/**
 * nodesSwap - function that swaps two nodes.
 * @h: pointer to the head of list.
 * @n1: pointer to the first node.
 * @n2: second node.
 */
void nodesSwap(listint_t **head, listint_t **a, listint_t *b)
{
	(*a)->next = b->next;
	if (b->next != NULL)
		b->next->prev = *a;
	b->prev = (*a)->prev;
	b->next = *a;
	if ((*a)->prev != NULL)
		(*a)->prev->next = b;
	else
		*head = b;
	(*a)->prev = b;
	*a = b->prev;
}

/**
 * insertion_sort_list - function that sorts a list
 * 					(the insertion sort algorithm).
 * @list: pointer to the head of a list.
 * Description: prints the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *iter, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			nodesSwap(list, &insert, iter);
			print_list((const listint_t *)*list);
		}
	}
}
