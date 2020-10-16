#ifndef COMMANDS_REPL_H
#define COMMANDS_REPL_H

#include <stdbool.h>

bool __analyser_syntax(char* string, char* analyser);

char* check_syntax(char* string); 

void command_help();

void command_source(char* local_file);

void command_exit(char* exit_simbol);

void command_manual(char* manual_of_function);

void command_write(char* path_to_the_source);

#endif