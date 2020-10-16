#ifndef GET_COMMANDS_H
#define GET_COMMANDS_H

void  push_includes();

void push_main();

void get_makefile(int number_argument, char** components_in_main);

void control_exit(char* signal_out);

void get_source(const char* restrict __source_c);

void compile();


#endif