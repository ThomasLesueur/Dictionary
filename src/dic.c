#include "dic.h"

char *ltrim(char *s)
{
    while(isspace(*s)) s++;
    return s;
}

char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back+1) = '\0';
    return s;
}

char *trim(char *s)
{
    return rtrim(ltrim(s)); 
}

void insert_word(tree_node_t **tree)
{
    char *word = NULL;
    char *meaning = NULL;
    size_t size = 0;
    element_t elem;

    printf("Please enter a word : ");
    while(getline(&word, &size, stdin) < 0){}
    printf("Please enter a meaning : ");
    while(getline(&meaning, &size, stdin) < 0){}
    elem.word = trim(word);
    elem.mean = trim(meaning);
    *tree = insert(*tree, elem);
}

void delete_word(tree_node_t **tree)
{
    char *word = NULL;
    size_t size = 0;

    printf("Please enter a word to delete: ");
    while(getline(&word, &size, stdin) < 0){}
    word = trim(word);
    *tree = delete(*tree, word);
}

void search_word(tree_node_t *tree)
{
    char *word = NULL;
    size_t size = 0;
    element_t elem;

    printf("Please enter a word to search: ");
    while(getline(&word, &size, stdin) < 0){}
    word = trim(word);
    elem = get(tree, word);
    printf("Result for \"%s\":\n\t %s : %s\n", word, elem.word, elem.mean);
}

void print_dic(tree_node_t *tree)
{
    if (tree) {
        print_dic(tree->left);
        printf("%s : %s\n", tree->element.word, tree->element.mean);
        print_dic(tree->right);
    }
}

void print_node_nb(tree_node_t *tree)
{
    printf("Total number of nodes : %d\n", get_node_nb(tree));
}

void print_tree_height(tree_node_t *tree)
{
    printf("Height of the tree : %d\n", get_max_depth(tree));
}