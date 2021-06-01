#ifndef DIC_H
#define DIC_H

#include "menu.h"
#include "binary_tree.h"

void insert_word(tree_node_t **tree);
void delete_word(tree_node_t **tree);
void search_word(tree_node_t *tree);
void print_dic(tree_node_t *tree);
void print_tree_height(tree_node_t *tree);
int return_number_of_nodes(tree_node_t* tree);
void delete_all_nodes(tree_node_t *tree);
void print_node_nb(tree_node_t *tree);
void print_tree_height(tree_node_t *tree);

#endif /*DIC_H*/