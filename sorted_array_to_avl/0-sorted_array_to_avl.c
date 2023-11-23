#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * sorted_array_to_avl - a function that builds an AVL tree from an array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * Return: pointer to the root or null if failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (size == 0)
		return (NULL);
	int mediane;
	int newsize;
	avl_t *root;

	root = malloc(sizeof(avl_t));
	newsize = (size - 1) / 2;
	mediane = array[newsize];
	root->n = mediane;
	root->parent = NULL;

	root->left = sorted_array_to_avl(array, newsize);
	root->right = sorted_array_to_avl(&array[(newsize) + 1], (size / 2));
	if (root->left != NULL)
		root->left->parent = root;
	if (root->right != NULL)
		root->right->parent = root;

	return (root);
}
