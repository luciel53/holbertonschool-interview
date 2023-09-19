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
	listint_t *current = *head;
	/* create size variable to use in allocations */
	int size = 0;
	int i;
	int *array;
	int *copy;

	/* browse the list and iterate size of the future array */
	while (current != NULL)
	{
		current = current->next;
		size++;
	}

	/* allocate the array */
	array = (int *)malloc(sizeof(int) * size);
	/* allocate memory for the copy */
	copy = (int *)malloc(sizeof(int) * size);

	/* convert the singly linked list in array and recover data with &current */
	to_array(head, array);
	/* copy the array */
	for (i = 0; i < size; i++)
	{
		copy[i] = array[i];
	}

	/* checks if the array is a palindrome */
	for (i = 0; i < size; i++)
	{
		/* compare the 2 arrays */
		if (array[i] != copy[size - 1 - i])
		{
			return (0);
		}
	}
	return (1);
	free(copy);
}
