#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s heap_t;

typedef struct binary_tree_s binary_tree_t;


bool binary_tree_is_empty(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
int heap_extract(heap_t **root);

#endif /* BINARY_TREES_H */
