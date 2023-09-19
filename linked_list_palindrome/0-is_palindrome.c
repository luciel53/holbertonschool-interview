#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"


/**
 * to_array - function that converts a singly linked list to an array
 * @head: the head of the list
 * @array: the array created
 * Return: void
 */

void to_array(listint_t **head, int *array)
{
	listint_t *current = *head;
	int i = 0;

	while (current != NULL)
	{
		array[i] = current->n;
		current = current->next;
		i++;
	}
}


/**
 * is_palindrome - function to check if a singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 or 1 if palindrome
 */

int is_palindrome(listint_t **head)
{
	listint_t *node = *head;
	/* create size variable to use in allocations */
	int size = 0;
	/* allocate the array */
	int *array = (int *)malloc(sizeof(int) * size);

	if (node == NULL || node->next == NULL)
		return (1);

	while (node != NULL)
	{
		node = node->next;
		size++;
	}

	to_array(&node, array);

	int *copy = (int *)malloc(sizeof(int) * size);
	memcpy(copy, array, sizeof(int) * size);

	for (int i = 0; i < size; i++)
	{
		if (array[i] == copy[i])
			return (1);
		return (0);
	}
	return (0);
}
