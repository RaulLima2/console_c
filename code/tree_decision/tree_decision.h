#ifndef TREE_DECISION_H
#define TREE_DECISION_H

typedef struct tree TBS;

TBS* create(int size_string, void(*check)(char*));

TBS* insert(TBS* tree, int size_string, void(*check)(char*));

TBS* search(TBS* tree, int size_string);

void print_tbs(TBS* tree);

int color(TBS* tree);

void change_color(TBS* tree);

TBS* rotate_left(TBS* left);

TBS* rotate_right(TBS* right);

TBS* move_left_red(TBS* tree);

TBS* move_right_red(TBS* tree);

TBS* balancear(TBS* tree);

TBS* balancear_left_down(TBS* tree);

void execute_node(TBS* tree, char* string);

#endif