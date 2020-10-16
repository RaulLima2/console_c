#include <stdio.h>
#include <stdlib.h>
#include "../commands_repl_c/commands_repl.h"
#include "tree_decision.h"

#define RED 1
#define BLACK 0

struct tree 
{
    int cor;
    int info;
    TBS* left;
    TBS* right;

    void (*check)(char*);
};

TBS* create(int size_string, void(*check)(char*))
{
    TBS* new = (TBS*)malloc(sizeof(TBS));

    if(new == NULL)
    {
        fprintf(stderr,"\033[1;36m Not Allocated \n");
    }

    new->info = size_string;
    new->cor = BLACK;
    new->check = check;
    new->left = new->right = NULL;

    return new;
}

TBS* insert_node(TBS* tree, int size_string, void(*check)(char*))
{
    if(tree == NULL)
    {
        TBS* new = (TBS*)malloc(sizeof(TBS));

        if(new == NULL)
        {
            fprintf(stderr,"\033[1;36m Not Allocated \n");
        }

        new->info = size_string;
        new->cor = RED;
        new->check = check;
        new->left = new->right = NULL;

        return new;
    }

    if(size_string > tree->info)
    {
        tree->right = insert(tree->right, size_string, check);
    }
    else if(size_string < tree->info)
    {
        tree->left = insert(tree->left, size_string, check);
    }
    else
    {
        return tree;
    }

    tree = balancear_left_down(tree);


    return tree;
}

TBS* insert(TBS* tree, int size_string, void(*check)(char*))
{
    tree = insert_node(tree, size_string, check);

    if(tree != NULL)
    {
        tree->cor = BLACK;
    }
    
    return tree;
}

TBS* search(TBS* tree, int size_string)
{
    if(tree->info == size_string)
    {
        return tree;
    }
    else if(tree == NULL)
    {
        return NULL;
    }
    
    if(tree->info > size_string)
    {
        return search(tree->left, size_string);
    }
    else
    {
        return search(tree->right, size_string);
    }
}

void print_tbs(TBS* tree)
{
    if(tree != NULL)
    {
        print_tbs(tree->left);
        printf("%3d", tree->info);
        print_tbs(tree->right);
    }
}

int color(TBS* tree)
{
    if(tree == NULL)
    {
        return BLACK;
    }
    else
    {
        return tree->cor;
    }
}

void change_color(TBS* tree)
{
    tree->cor = !tree->cor;

    if(tree->left != NULL)
    {
        tree->left->cor = !tree->left->cor;
    }
    
    if(tree->right != NULL)
    {
        tree->right->cor = !tree->right->cor;
    }
}

TBS* rotate_left(TBS* left)
{
    TBS* right = left->right;
    left->right = right->left;
    right->left = left;
    right->cor = left->cor;
    left->cor = RED;
    return right;
}

TBS* rotate_right(TBS* right)
{
    TBS* left = right->left;
    right->left = left->right;
    left->right = right;
    left->cor = right->cor;
    right->cor = RED;
    return left;
}

TBS* move_left_red(TBS* tree)
{
    change_color(tree);

    if(color(tree->right->left) == RED)
    {
        tree->right = rotate_right(tree->right);
        tree = rotate_left(tree);
        color(tree);
    }

    return tree;
}

TBS* move_right_red(TBS* tree)
{
    change_color(tree);

    if(color(tree->left->left) == RED)
    {
        tree = rotate_right(tree);
        color(tree);
    }

    return tree;
}

TBS* balancear(TBS* tree)
{
    if(color(tree->right) == RED)
    {
        tree = rotate_left(tree);
    }

    if((tree->left != NULL) && (color(tree->right) == RED) && (color(tree->left->left) == RED))
    {
        tree = rotate_right(tree);
    }

    if((color(tree->left) == RED) && (color(tree->right) == RED))
    {
       change_color(tree); 
    }

    return tree;
}

TBS* balancear_left_down(TBS* tree)
{
    if(color(tree->right) == RED && color(tree->left) == BLACK)
    {
        tree = rotate_left(tree);
    }

    if(color(tree->right) == RED && color(tree->left) == RED)
    {
        tree = rotate_right(tree);
    }

    if(color(tree->left) == RED && color(tree->right) == RED)
    {
        change_color(tree);
    }

    return tree;
}

void execute_node(TBS* tree, char* string)
{
    tree->check(string);
}