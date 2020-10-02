#ifndef GET_COMMANDS_H
#define GET_COMMANDS_H

int  push_includes(int number_includes, char* arguments_includes);

void push_main(int number_spaces_includes_fseek);

void get_makefile(int number_argument, char* components_in_main);

void control_exit(char* signal_out);

void get_source(const char* restrict __source_c);

void compile();


#endif