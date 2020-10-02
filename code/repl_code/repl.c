#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_commands/get_commands.h"
#include "repl.h";


void shell_start()
{
    string print_shell[] = {
        "Console C 2020-0.1 version",
        "lisence GNU"};

    for(i = 0; i < 2; i++)
    {
        printf("%s\n",print_shell[i]);
    }
}


void repl()
{
    int number_include = 0;

    bool check = true;

    shell_start();

    while(check)
    {
        number_include = push_includes();
        push_main(number_include);

        compile();
    }
}