#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * check_cycle - checks if a singly linked list has a cycle in it
 * @list: the list to check
 * Return: 0 if no cycle, 1 if cycle
 */

int check_cycle(listint_t *list)
{
	if (list == NULL)
		return 0;

	listint_t *ptr1 = list;
	listint_t *ptr2 = list;

	/* browse the list with 2 different pointers */
	while (ptr1 != NULL && ptr2 != NULL)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next->next;

		/* if the 2 pointers meet at the same node -> cycle */
		if (ptr2 == ptr1)
			return (1);
	}

	return (0);
}
