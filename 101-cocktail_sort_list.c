#include "sort.h"

void swapNextNode(listint_t **head, listint_t **tail, listint_t **shake);
void swapPrevNode(listint_t **head, listint_t **tail, listint_t **shake);
void cocktail_sort_list(listint_t **list);

/**
 * swapNextNode - Exchange a node in a listint_t doubly-linked list
 * consisting of integers with the next node.
 * @head: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shake: pointer to current node being swapped (cocktail shaker algorithm).
 */

void swapNextNode(listint_t **head, listint_t **tail, listint_t **shake)
{
	listint_t *old = (*shake)->next;

	if ((*shake)->prev != NULL)
		(*shake)->prev->next = old;
	else
		*head = old;
	old->prev = (*shake)->prev;
	(*shake)->next = old->next;
	if (old->next != NULL)
		old->next->prev = *shake;
	else
		*tail = *shake;
	(*shake)->prev = old;
	old->next = *shake;
	*shake = old;
}

/**
 * swapPrevNode - Exchange a node in a listint_t doubly-linked
 * list of integers with the preceding node.
 * @head: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @shake: pointer to node being swapped (the cocktail shaker algorithm).
 */

void swapPrevNode(listint_t **head, listint_t **tail, listint_t **shake)
{
	listint_t *old = (*shake)->prev;

	if ((*shake)->next != NULL)
		(*shake)->next->prev = old;
	else
		*tail = old;
	old->next = (*shake)->next;
	(*shake)->prev = old->prev;
	if (old->prev != NULL)
		old->prev->next = *shake;
	else
		*head = *shake;
	(*shake)->next = old;
	old->prev = *shake;
	*shake = old;
}

/**
 * cocktail_sort_list - Arrange a listint_t doubly-linked list of integers in
 * ascending order utilizing the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shake;
	boolean notStirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (notStirred == false)
	{
		notStirred = true;
		for (shake = *list; shake != tail; shake = shake->next)
		{
			if (shake->n > shake->next->n)
			{
				swapNextNode(list, &tail, &shake);
				print_list((const listint_t *)*list);
				notStirred = false;
			}
		}
		for (shake = shake->prev; shake != *list;
				shake = shake->prev)
		{
			if (shake->n < shake->prev->n)
			{
				swapPrevNode(list, &tail, &shake);
				print_list((const listint_t *)*list);
				notStirred = false;
			}
		}
	}
}
