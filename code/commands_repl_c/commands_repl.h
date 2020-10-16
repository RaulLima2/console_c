#ifndef COMMANDS_REPL_H
#define COMMANDS_REPL_H

typedef struct tree TBS;

TBS* create(int size_string);

TBS* insert(TBS* tree, int size_string);

TBS* search(TBS* tree, int size_string);

void check_syntax(char* string);

void command_help(char* name_function);

void command_source(char* local_file);

void command_exit(char* exit_simbol);

#endif