#ifndef COMMANDS_H
#define COMMANDS_H

#define MAX_ALLOCATE 500

void __help();

void __quit();

void __source(char* __file_code);

void __manual(char* name_function);

void __write(char* __path_to_the_source);

#endif