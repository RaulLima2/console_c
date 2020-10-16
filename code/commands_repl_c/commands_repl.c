#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../commands/commands.h"
#include "commands_repl.h"

struct tree 
{
    int info;
    TBS* left;
    TBS* right;

    void (*check)(char*);
};

const char* __commands[] = {
    "q",
    "source",
    "help"
};

TBS* create(int size_string)
{
    TBS* new = (TBS*)malloc(sizeof(TBS));

    new->info = size_string;
    new->left = new->right = NULL;
    return new;
}

TBS* insert(TBS* tree, int size_string)
{
    if(tree == NULL)
    {
        return create(size_string);
    }

    if(size_string > tree->info)
    {
        tree->right = insert(tree->right, size_string);
    }
    else
    {
        tree->left = insert(tree->left, size_string);
    }

    retun tree;
}

TBS* search(TBS* tree, int size_string)
{
    if(key == size_string)
    {
        return tree;
    }
    else
    {
        search(tree->left, size_string);
        search(tree->right, size_string);
    }
    
}

void check_syntax(char* string)
{
    TBS* tree_decision = create(strlen(__commands[2]));
    insert(tree_decision, strlen(__commands[0]));
    insert(tree_decision, strlen(__commands[1]));

    tree_decision->check = command_help;
    tree_decision->left->check = command_exit;
    tree_decision->check = command_source;

    TBS* i = search(tree_decision, );
    

}

void command_help(char* name_function)
{
    bool check = true;
    char* temp = (char*)calloc(100, sizeof(char));

    strncat(temp,"man ", strlen("man "));
    strncat(temp, name_function + 5, strlen(name_function));

    check = strncmp(__commands[2], name_function, 4);

    if(check)
    {
        help(temp);
    }
}

void command_source(char* local_file)
{
    bool check = true;
    char* temp = (char*)calloc(100, sizeof(char));


    check = strncmp(local_file, __commands[1], strlen(__commands[1]));

    strncpy(temp, local_file + 7, strlen(local_file) - 1);

    if(check)
    {
        source(temp);
    }
}


void command_exit(char* exit_simbol)
{
    bool check = true;

    check = strncmp(exit_simbol, __commands[0], strlen(__commands[0]));

    if(check)
    {
        quit();
    }
}