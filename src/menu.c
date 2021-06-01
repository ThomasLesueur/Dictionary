#include "menu.h"

char get_user_input()
{
    char *str;
    size_t size = 0;

    printf("Please enter a Value : ");
    while(getline(&str, &size, stdin) > 0) {
        if (strlen(str) > 2 || isdigit(str[0]) == 0 ||
        ((isdigit(str[0]) != 0) && (str[0] < '1' || str[0] > '8'))) {
            printf("Error : Please enter a number between 1 and 8\n");
            printf("\nPlease enter a Value : ");
        }
        else
            break;
    }
    return str[0];
}

void print_menu()
{
    printf("*----------------------------*\n");
    printf("\t\t 1 : Insert\n");
    printf("\t\t 2 : Delete\n");
    printf("\t\t 3 : Search\n");
    printf("\t\t 4 : Print\n");
    printf("\t\t 5 : Exit\n");
    printf("\t\t 6 : Print height of the tree\n");
    printf("\t\t 7 : Output the total number of nodes\n");
    printf("\t\t 8 : Delete all nodes\n");
    printf("*----------------------------*\n");
}

void call_function(char input, tree_node_t **tree)
{
    switch (input)
    {
    case '1':
        insert_word(tree);
        break;
    case '2':
        delete_word(tree);
        break;
    case '3':
        search_word(*tree);
        break;
    case '4':
        print_dic(*tree);
        break;
    case '6':
        print_tree_height(*tree);
        break;
    case '7':
        print_node_nb(*tree);
        break;
    case '8':
        delete_tree(*tree);
        *tree = NULL;
        printf("All nodes removed\n");
        break;
    default:
        break;
    }
}

int loop_menu()
{
    tree_node_t *tree = NULL;
    char input = '\0';
    do {
        print_menu();
        input = get_user_input();
        call_function(input, &tree);
    } while (input != '5');
    return 0;
}