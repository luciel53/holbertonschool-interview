#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdlib.h>
#include <stdio.h>


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

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

int binary_tree_is_avl(const binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree, int min, int max);
static void binary_tree_print(const binary_tree_t *tree);
size_t _height(const binary_tree_t *tree);
int is_bst(const binary_tree_t *tree, int low, int high);
static int get_height(const binary_tree_t *tree);
int abs_diff(int a, int b);
int print_t(const binary_tree_t *tree, int offset, int depth, char **s);
binary_tree_t *basic_tree(void);
int main(void);
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);


#endif /* _BINARY_TREES_H_ */
