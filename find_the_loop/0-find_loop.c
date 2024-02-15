#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"


/**
 * find_listint_loop - function that finds the loop in a linked list.
 * @head: the head of the list
 * Return: address of node where the loop starts or NULL if there is no loop
 */

listint_t *find_listint_loop(listint_t *head)
{
    listint_t *ptr1 = head;
    listint_t *ptr2 = head;

    while (ptr2 != NULL && ptr2->next != NULL) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;

        /* If ptr1 and ptr2 pointers meet, there's a loop */
        if (ptr1 == ptr2) {
            /* Move ptr1 to head. Keep ptr2 at meeting point. */
            ptr1 = head;
            while (ptr1 != ptr2) {
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }
            return (ptr1); /* Returns the node where the loop starts */
        }
    }

    return (NULL); /* No loop found */
}

