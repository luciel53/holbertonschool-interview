#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
	* A function in C that inserts a number into a sorted singly linked list.
	* @head: pointer to the head of the list
	* @number: value of the new node
	* Return: the adress of the new node
*/

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node, *temp;
	temp = *head;

	/* Allocate new_node */
	new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
		return NULL;

	/* set new_node */
	new_node->n = number;
	new_node->next = NULL;

	/* if empty list, new_node is the first node */
	if (*head == NULL) {
		*head = new_node;
		return new_node;
	}

	if (head != NULL) {
		/* if number is < head value (temp) new_node is first node */
		if (number < temp->n) {
			new_node->next = temp;
			*head = new_node;
			return new_node;
		}
		/* Else browse the list */
		while (temp->next != NULL) {
			/* if number > previous node and < next node, insert it */
			if (number > temp->n && number < temp->next->n) {
				new_node->next = temp->next;
				temp->next = new_node;
				return new_node;
			}
			/* else if number > previous and next node, continue to browse */
			else if (number > temp->n && number > temp->next->n) {
				temp = temp->next;
			}
		}
		/* to insert the node at the end of the list */
		temp->next = new_node;
	}
	return (new_node);
}


