#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

size_t tree_size(const heap_t *root);
heap_t *get_last_node(heap_t *root);
void heapify_down(heap_t *root, int value);

/**
 * tree_size - Calculate the size of a binary tree
 * @root: head of tree
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t tree_size(const heap_t *root)
{
	if (root == NULL)
		return (0);

	return (1 + tree_size(root->left) + tree_size(root->right));
}

/**
 * get_last_node - Get the last node in the heap
 * @root: head of tree
 * Return: last node
 */
heap_t *get_last_node(heap_t *root)
{
	if (root == NULL)
		return (NULL);

	while (root->left || root->right)
	{
		if (tree_size(root->left) > tree_size(root->right))
			root = root->left;
		else
			root = root->right;
	}

	return (root);
}

/**
 * heapify_down - Heapify the heap down from the given node
 * @root: head of tree
 * @value: value to swap
 */
void heapify_down(heap_t *root, int value)
{
	if (root == NULL)
		return;

	heap_t *largest = root;
	heap_t *left_child = root->left;
	heap_t *right_child = root->right;

	if (left_child && left_child->n > largest->n)
		largest = left_child;

	if (right_child && right_child->n > largest->n)
		largest = right_child;

	if (largest != root)
	{
		int temp = root->n;

		root->n = largest->n;
		largest->n = temp;

		heapify_down(largest, value);
	}

	else if (root->left && root->left->n == value)
	{
		int temp = root->n;

		root->n = root->left->n;
		root->left->n = temp;
	}
	else if (root->right && root->right->n == value)
	{
		int temp = root->n;

		root->n = root->right->n;
		root->right->n = temp;
	}
}

/**
 * heap_extract - Extract the root node of a Max Binary Heap
 * @root: head of tree
 * Return: extracted value
 */
int heap_extract(heap_t **root)
{
	if (root == NULL)
		return (0);
	if (*root == NULL)
		return (0);

	int extracted_value = (*root)->n;

	heap_t *last_node = get_last_node(*root);

	if (last_node == *root)
	{
		free(*root);
		*root = NULL;
		return (extracted_value);
	}

	(*root)->n = last_node->n;

	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	free(last_node);

	heapify_down(*root, extracted_value);

	return (extracted_value);
}
