#include "binary_tree.h"

tree_node_t *insert(tree_node_t *tree_ptr, element_t elem)
{
    tree_node_t *new = NULL;
    int compare = 0;


    if (tree_ptr == NULL) {
        new = malloc(sizeof(*new));
        new->element = elem;
        new->left = NULL;
        new->right = NULL;
        return new;
    }
    else {
        compare = strcmp(elem.word, tree_ptr->element.word);
        if (compare < 0) {
            tree_ptr->left = insert(tree_ptr->left, elem);
            return tree_ptr;
        }
        else if (compare > 0) {
            tree_ptr->right = insert(tree_ptr->right, elem);
            return tree_ptr;
        }
        else {
            printf("Word \"%s\" already exist.\n", elem.word);
            return tree_ptr;
        }
    }
}



/* Given a non-empty binary search
   tree, return the node
   with minimum key value found in
   that tree. Note that the
   entire tree does not need to be searched. */
tree_node_t* get_leftmost(tree_node_t* node)
{
    tree_node_t* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
 
/* Given a binary search tree
   and a key, this function
   deletes the key and
   returns the new node */
tree_node_t* delete(tree_node_t* node, char *elem)
{
    // base case
    if (node == NULL)
        return node;
 
    // If the key to be deleted
    // is smaller than the node's
    // key, then it lies in left subtree
    if (strcmp(elem, node->element.word) < 0)
        node->left = delete(node->left, elem);
 
    // If the key to be deleted
    // is greater than the node's
    // key, then it lies in right subtree
    else if (strcmp(elem, node->element.word) > 0)
        node->right = delete(node->right, elem);
 
    // if key is same as node's key,
    // then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (node->left == NULL) {
            tree_node_t* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            tree_node_t* temp = node->left;
            free(node);
            return temp;
        }
 
        // node with two children:
        // Get the inorder successor
        // (smallest in the right subtree)
        tree_node_t* temp = get_leftmost(node->right);
 
        // Copy the inorder
        // successor's content to this node
        node->element = temp->element;
 
        // Delete the inorder successor
        node->right = delete(node->right, temp->element.word);
    }
    return node;
}

element_t get(tree_node_t *tree, char *query)
{
    element_t def;

    def.word = "default";
    def.mean = "No result found";

    int compare = 0;
    if (tree == NULL)
        return def;
    compare = strcmp(query, tree->element.word);
    if (compare < 0)
        return get(tree->left, query);
    else if (compare > 0)
        return get(tree->right, query);
    else
        return tree->element;
}

int get_max_depth(tree_node_t* tree)
{
    int left = 0;
    int right = 0;

    if (tree == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        left = get_max_depth(tree->left);
        right = get_max_depth(tree->right);
        /* use the larger one */
        return left > right ? left + 1 : right + 1;
    }
}

int get_node_nb(tree_node_t *tree)
{
    int nb = 1;
    if (tree) {
        nb += get_node_nb(tree->left);
        nb += get_node_nb(tree->right);
        return nb;
    }
    return 0;
}

void delete_tree(tree_node_t *tree)
{
    if (tree) {
        delete_tree(tree->left);
        delete_tree(tree->right);
        free(tree);
    }
}

