#include "sort.h"

/**
 * nodesSwap - function that swaps two nodes.
 * @head: pointer to the head of list.
 * @a: pointer to the first node.
 * @b: second node.
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
 * (the insertion sort algorithm).
 * @list: pointer to the head of a list.
 * Description: prints the list after each swap.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *itr, *ins, *old;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (itr = (*list)->next; itr != NULL; itr = old)
	{
		old = itr->next;
		ins = itr->prev;
		while (ins != NULL && itr->n < ins->n)
		{
			nodesSwap(list, &ins, itr);
			print_list((const listint_t *)*list);
		}
	}
}
