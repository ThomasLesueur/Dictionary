#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_WORD_LENGTH 20
#define MAX_MEAN_LENGTH 200

typedef struct element_s {
    char *word;
    char *mean;
} element_t;

typedef struct tree_node_s {
    element_t element;
    struct tree_node_s *left;
    struct tree_node_s *right;
} tree_node_t;

tree_node_t *insert(tree_node_t *tree_ptr, element_t elem);
tree_node_t *delete(tree_node_t *tree_ptr, char *elem);
element_t get(tree_node_t *tree_ptr, char *elem);
int get_node_nb(tree_node_t *tree);
int get_max_depth(tree_node_t* tree);
void delete_tree(tree_node_t *tree);

#endif /*BINARY_TREE_H*/