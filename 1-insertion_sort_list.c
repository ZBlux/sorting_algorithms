#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: the list to be sorted
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *p, *num;
	int c = 0;

	if (list)
		head  = *list;
	else
		return;

	if (head->next)
		c = 1;
	while (head && c == 1)
	{
		p = head->prev;
		num = head;
		while (p && num->n < p->n)
		{
			if (p->prev)
				p->prev->next = num;
			p->next = num->next;
			num->prev = p->prev;
			p->prev = num;
			num->next = p;
			if (p->next)
				p->next->prev = p;

			p = num->prev;
			if (!num->prev)
				*list = num;
			print_list(*list);
		}
		head = head->next;
	}
}
