#include "binary_trees.h"
#include <limits.h>

int abs_diff(int a, int b) {
  return (a > b) ? (a - b) : (b - a);
}

int max(int a, int b) {
  return (a > b) ? a : b;
}

int height(const binary_tree_t *tree) {
    int left_height, right_height;
  if (tree == NULL) {
    return 0;
  }

  left_height = height(tree->left);
  right_height = height(tree->right);

  return 1 + max(left_height, right_height);
}

int is_bst(const binary_tree_t *tree, int low, int high) {
  if (tree == NULL) {
    return 1;
  }

  if (tree->n <= low || tree->n >= high) {
    return 0;
  }

  return is_bst(tree->left, low, tree->n) && is_bst(tree->right, tree->n + 1, high);
}

int binary_tree_is_avl(const binary_tree_t *tree) {
  int left_height, right_height, balance_factor;

  if (tree == NULL) {
    return 0;
  }

  if (!is_bst(tree, INT_MIN, INT_MAX)) {
    return 0;
  }

  left_height = height(tree->left);
  right_height = height(tree->right);

  balance_factor = abs_diff(left_height, right_height);

  return balance_factor < 1;
}
